#include "imlib/list/list.h"

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/immem.h"

PRIVATE void __constructor__(register void *const self,
                             register struct ImParams *args) {
  (void)self, (void)args;
}

PRIVATE void __destructor__(register void *const self) { (void)self; }

PUBLIC void ImIList_SetPolicy(register void *const list,
                              register enum DataPolicy const policy) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  klass->implof(self);
  self->set_policy(list, policy);
  (void)imdel(self);
}

PUBLIC void ImIList_PushBack(register void *const list,
                             register void const *const data) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  klass->implof(self);
  self->push_back(list, data);
  (void)imdel(self);
}

/*
PUBLIC void *ImIList_PopFront(register void *const list) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  register void *ret = NULL;
  klass->implof(self);
  ret = self->pop_front(list);
  (void)imdel(self);
  return ret;
}
*/

CLASS(ImIList) {
  _ImIList.size = sizeof(struct ImIList);
  _ImIList.ctor = __constructor__;
  _ImIList.dtor = __destructor__;
}
