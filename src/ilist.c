#include "imlib/list/ilist.h"

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/imerror.h"
#include "imlib/immem.h"
#include "imlib/imoption.h"
#include "imlib/imresult.h"

PRIVATE void __constructor__(register void *const self,
                             register struct ImParams *args) {
  (void)self, (void)args;
}

PRIVATE void __destructor__(register void *const self) { (void)self; }

PUBLIC size_t ImIList_Len(register void *const list) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  register size_t len = 0u;
  klass->implof(self);
  len = self->len(list);
  (void)imdel(self);
  return len;
}

PUBLIC struct ImResPtr ImIList_Get(register void *const list,
                                   register size_t const index) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  register struct ImResPtr res = {0};
  klass->implof(self);
  res = self->get(list, index);
  (void)imdel(self);
  return res;
}

PUBLIC void ImIList_SetPolicy(register void *const list,
                              register enum DataPolicy const policy) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  klass->implof(self);
  self->set_policy(list, policy);
  (void)imdel(self);
}

PUBLIC struct ImResInt ImIList_Insert(register void *const list,
                                      register size_t const index,
                                      register void *const data) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  register struct ImResInt res = {0};
  klass->implof(self);
  res = self->insert(list, index, data);
  (void)imdel(self);
  return res;
}

PUBLIC void ImIList_Append(register void *const list,
                           register void const *const data) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  klass->implof(self);
  self->append(list, data);
  (void)imdel(self);
}

PUBLIC struct ImResInt ImIList_Remove(register void *const list,
                                      register size_t const index) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  register struct ImResInt res = {0};
  klass->implof(self);
  res = self->remove(list, index);
  (void)imdel(self);
  return res;
}

PUBLIC struct ImOptULong ImIList_IndexOf(register void *const list,
                                         register void const *const data) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  register struct ImOptULong opt = {0};
  klass->implof(self);
  opt = self->index_of(list, data);
  (void)imdel(self);
  return opt;
}

PUBLIC void ImIList_Retain(register void *const list,
                           register ImBool (*predicate)(void const *)) {
  register struct ImIList *self = imnew(ImIList, 0u);
  register struct ImClass *klass = imclass(list);
  klass->implof(self);
  self->retain(list, predicate);
  (void)imdel(self);
}

CLASS(ImIList) {
  _ImIList.size = sizeof(struct ImIList);
  _ImIList.ctor = __constructor__;
  _ImIList.dtor = __destructor__;
}
