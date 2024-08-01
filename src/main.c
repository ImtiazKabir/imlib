#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"

#include "imlib/imerrno.h"
#include "imlib/imerror.h"
#include "imlib/imlog.h"
#include "imlib/immem.h"
#include "imlib/imoption.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imresult.h"
#include "imlib/imstdinc.h"
#include "imlib/imstr.h"

struct Parent {
  int iq;
  void (*greet)(void const *_self);
};

PRIVATE void __parent_greet__(register void const *const _self) {
  register struct Parent const *const self = _self;
  imlog1(LOG_TRACE, "Hello from parent(iq = %d)", self->iq);
}

PRIVATE void __parent_ctor__(register void *const _self,
                             register struct ImParams *args) {
  register struct Parent *const self = _self;
  register int const iq = args->params[0].value.int_rep;

  imlog(LOG_TRACE, "In parent constructor");

  self->iq = iq;
  self->greet = __parent_greet__;
}

PRIVATE void __parent_dtor__(register void *const _self) {
  (void)_self;
  imlog(LOG_TRACE, "In parent destructor");
}

CLASS(Parent) {
  _Parent.size = sizeof(struct Parent);
  _Parent.ctor = __parent_ctor__;
  _Parent.dtor = __parent_dtor__;
}

struct Child {
  struct Parent base;
  int age;
  void (*greet)(void const *_self);
};

PRIVATE void __child_greet__(register void const *const _self) {
  register struct Child const *const self = _self;
  imlog1(LOG_TRACE, "Hello from child(age = %d)", self->age);
}

PRIVATE void __child_ctor__(register void *const _self,
                            register struct ImParams *args) {
  register struct Child *const self = _self;
  register int const age = args->params[0].value.int_rep;

  imlog(LOG_TRACE, "In child constructor");

  self->age = age;
  self->greet = __child_greet__;
  /* uncomment following line to set as virtual */
  self->base.greet = __child_greet__;
}

PRIVATE void __child_dtor__(register void *const _self) {
  (void)_self;
  imlog(LOG_TRACE, "In child destructor");
}

PRIVATE void __child_super_params__(register struct ImParams *sup_args,
                                    register struct ImParams *self_args) {
  (void)self_args;
  ImParams_Push(sup_args, 1u, PARAM_INT, 100);
}

CLASS(Child) {
  _Child.size = sizeof(struct Child);
  _Child.super_class = Parent;
  _Child.ctor = __child_ctor__;
  _Child.dtor = __child_dtor__;
  _Child.super_params = __child_super_params__;
}

IM_DECLARE_ERROR(TestError)
IM_DEFINE_ERROR(TestError, 30, "Demo")

PRIVATE void TestErrorDemo(void) {
  register struct ImError *error = imnew(TestError, 0u);
  imlog3(LOG_ERROR, "%s %d %s", imtype(error), error->code, error->desc);
  if (imisof(error, TestError)) {
    imlog(LOG_INFO, "It is of Test Error");
  }
  if (imisof(error, ImError)) {
    imlog(LOG_INFO, "It is of ImError");
  }
  imdel(error);
}

PRIVATE void
AFunctionThatExpectsParent(register struct Parent const *const parent) {
  imlog(LOG_INFO, "From a parent pointer");
  parent->greet(parent); /* Still calls child's greet due to virtual override */
}

PRIVATE void
AFunctionThatExpectsChild(register struct Child const *const child) {
  imlog(LOG_INFO, "From a child pointer");
  child->greet(child);
}

PRIVATE void InheritanceDemo(void) {
  register struct Child *const child = imnew(Child, 1u, PARAM_INT, 20);
  AFunctionThatExpectsParent((struct Parent const *)child);
  AFunctionThatExpectsChild(child);
  if (imisof(child, Parent)) {
    imlog(LOG_INFO, "It is also a parent");
  }
  imdel(child);
}

PRIVATE void TypeHintDemo(void) {
  register int *const numptr = imalloct("Number", sizeof(*numptr));
  if (strcmp(imtype(numptr), "String")) {
    imlog1(LOG_ERROR, "It is actually %s", imtype(numptr));
  }
  imfree(numptr);
}

PRIVATE void TypeHintDemo2(void) {
  register int *numptr = imalloct("Number", sizeof(*numptr));
  register int i = 0;
  imfree(numptr);
  for (i = 0; i < 10; i++) {
    printf("%d\n", i);
    numptr = imalloct("Number", sizeof(*numptr));
    imfree(numptr);
  }
}

PRIVATE void StringDemo(void) {
  register struct ImStr *str1 = imnew(ImStr, 0u);
  ImStr_AppendFmt(str1, "This is soo freaking good %d", 2024);
  imputobj(str1, stdout);
  imdel(str1);
}

enum { DivisionByZeroError = 1 };

PRIVATE double GetReciprocal(register double const num) {
  if (num == 0.0) {
    imerr(DivisionByZeroError, "Argument was zero");
    return 0.0;
  }
  return 1.0 / num;
}

PRIVATE void ErrorDemo(void) {
  register double const num = GetReciprocal(0.0);
  if (imerrno() != IM_OK) {
    imlog2(LOG_ERROR, "%s (%d)", imerrmsg(), imerrno());
    imclrerr();
    return;
  }
  imlog1(LOG_INFO, "Reciprocal = %f", num);
}

IM_DECLARE_OPTION(OptionInt, int)
IM_DEFINE_OPTION(OptionInt, int)

IM_DECLARE_OPTION(OptionInteger, int)
IM_DEFINE_OPTION(OptionInteger, int)

PRIVATE struct OptionInteger OptionTest(void) {
  struct OptionInt opt = OptionInt_Some(4);
  int x;
  if (OptionInt_IsNone(&opt)) {
    imlog(LOG_TRACE, "none");
  }
  if (OptionInt_IsSome(&opt)) {
    imlog(LOG_TRACE, "some");
  }
  OPTION_TRY(x, OptionInt, opt, OptionInteger);
  return OptionInteger_None();
}

IM_DECLARE_RESULT(ResultInt, int)
IM_DEFINE_RESULT(ResultInt, int)

PRIVATE struct ResultInt ResultDemo(void) {
  struct ImError *error = imnew(TestError, 0u);
  struct ResultInt res = ResultInt_Err(error);
  int x;
  x = ResultInt_Unwrap(&res);
  RESULT_TRY(x, ResultInt, res, ResultInt);
  imlog1(LOG_INFO, "%d", x);
  return res;
}

int main(register int const argc, register char const *const *const argv) {
  (void)argc;
  trace_target = argv[0];

  InheritanceDemo();

  return EXIT_SUCCESS;
}
