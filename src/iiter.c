#include "imlib/iiter.h"

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/immem.h"
#include "imlib/imoption.h"

PRIVATE void __constructor__(register void *const self,
                             register struct ImParams *args) {
  (void)self, (void)args;
}

PRIVATE void __destructor__(register void *const self) { (void)self; }

PUBLIC struct ImOptPtr ImIIter_Next(register void *const iter) {
  register struct ImIIter *self = imnew(ImIIter, 0u);
  register struct ImClass *klass = imclass(iter);
  register struct ImOptPtr ret = ImOptPtr_None();
  klass->implof(self);
  ret = self->next(iter);
  (void)imdel(self);
  return ret;
}

PUBLIC void ImIIter_ForEach(register void *const list,
                            register void (*func)(void *, void *),
                            register void *const ret) {
  register struct ImIIter *self = imnew(ImIIter, 0u);
  register struct ImClass *klass = imclass(list);
  klass->implof(self);
  self->foreach (list, func, ret);
  (void)imdel(self);
}

CLASS(ImIIter) {
  _ImIIter.size = sizeof(struct ImIIter);
  _ImIIter.ctor = __constructor__;
  _ImIIter.dtor = __destructor__;
}
