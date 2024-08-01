#include "imlib/imerror.h"

#include <string.h>

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/immem.h"

#include "imlib/imparam.h"
#include "imlib/imstdinc.h"

PUBLIC void ErrorCtor(register void *const self,
                      register struct ImParams *const args) {
  (void)self;
  (void)args;
}

PUBLIC void ErrorDtor(register void *const self) { (void)self; }

PRIVATE char *__dupstr__(register char const *const src) {
  return strcpy(calloc(strlen(src) + 1u, sizeof(*src)), src);
}

PRIVATE void __constructor__(register void *const _self,
                             register struct ImParams *args) {
  register struct ImError *const self = _self;
  register int const code = args->params[0u].value.int_rep;
  register char const *const desc = args->params[1u].value.pointer_rep;

  self->code = code;
  self->desc = __dupstr__(desc);
}

PRIVATE void __destructor__(register void *const _self) {
  register struct ImError *const self = _self;

  self->code = 0;

  imfree(self->desc);
  self->desc = NULL;
}

PRIVATE char *__tostr__(register void const *const _self) {
  register struct ImError const *const self = _self;
  return __dupstr__(self->desc);
}

CLASS(ImError) {
  _ImError.size = sizeof(struct ImError);
  _ImError.ctor = __constructor__;
  _ImError.dtor = __destructor__;
  _ImError.tostr = __tostr__;
}
