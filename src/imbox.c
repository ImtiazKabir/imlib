#include "imlib/imbox.h"

#include <string.h>

#include "imlib/imclass_prot.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"

PRIVATE void __constructor__(register void *const _self,
                             register struct ImParams *args) {
  register struct ImBox *const self = _self;
  register void *const data = args->params[0u].value.pointer_rep;
  register struct ImBoxMethod *method = args->params[1u].value.pointer_rep;

  (void)memcpy(&self->method, method, sizeof(self->method));

  self->data = self->method.clone(data);
}

PRIVATE void __destructor__(register void *const _self) {
  register struct ImBox *const self = _self;
  self->method.dtor(self->data);
}

PRIVATE void __clone__(register void *const _self,
                       register void const *const _from) {
  register struct ImBox *const self = _self;
  register struct ImBox const *const from = _from;
  self->data = self->method.clone(from->data);
}

PRIVATE void __assign__(register void *const _self,
                        register void const *const _from) {
  register struct ImBox *const self = _self;
  register struct ImBox const *const from = _from;
  self->method.assign(self->data, from->data);
}

PRIVATE int __compare__(register void const *const _a,
                        register void const *const _b) {
  register struct ImBox const *const a = _a;
  register struct ImBox const *const b = _b;
  return a->method.compare(a, b);
}

PRIVATE char *__tostr__(register void const *const _self) {
  register struct ImBox const *const self = _self;
  return self->method.tostr(self->data);
}

CLASS(ImBox) {
  _ImBox.size = sizeof(struct ImBox);
  _ImBox.ctor = __constructor__;
  _ImBox.dtor = __destructor__;
  _ImBox.clone = __clone__;
  _ImBox.assign = __assign__;
  _ImBox.compare = __compare__;
  _ImBox.tostr = __tostr__;
}
