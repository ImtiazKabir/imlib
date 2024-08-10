#include "imlib/imerror.h"

#include <string.h>

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/immem.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"

PRIVATE char *__dupstr__(register char const *const src) {
  return strcpy(calloc(strlen(src) + 1u, sizeof(*src)), src);
}

PUBLIC void __init__(struct ImError *self, int code, char const *desc) {
  self->code = code;
  self->desc = __dupstr__(desc);
}

PUBLIC void __deinit__(struct ImError *self) {
  self->code = 0;

  (void)imfree(self->desc);
  self->desc = NULL;
}

PRIVATE void __constructor__(register void *const _self,
                             register struct ImParams *args) {
  register struct ImError *const self = _self;
  auto int code = 0;
  auto char const *desc = NULL;
  if (ImParams_Match(args, 2u, PARAM_INT, PARAM_PTR) == IM_FALSE) {
    impanic("%s\n", "ImError constructor takes (int, char const *)");
  }
  ImParams_Extract(args, &code, &desc);

  __init__(self, code, desc);
}

PRIVATE void __destructor__(register void *const self) { __deinit__(self); }

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
