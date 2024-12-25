#include "imlib/map/imap.h"
#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/imerror.h"
#include "imlib/immem.h"
#include "imlib/imoption.h"
#include "imlib/imresult.h"
#include "imlib/imstdinc.h"

PRIVATE void __constructor__(register void *const self,
                             register struct ImParams *args) {
  (void)self, (void)args;
}

PRIVATE void __destructor__(register void *const self) { (void)self; }

PUBLIC size_t ImIMap_Len(register void *const map) {
  register struct ImIMap *self = imnew(ImIMap, 0u);
  register struct ImClass *klass = imclass(map);
  register size_t len = 0u;
  klass->implof(self);
  len = self->len(map);
  (void)imdel(self);
  return len;
}

PUBLIC struct ImOptPtr ImIMap_Get(register void *const map, register void const *const key) {
  register struct ImIMap *self = imnew(ImIMap, 0u);
  register struct ImClass *klass = imclass(map);
  register struct ImOptPtr ret = {0};
  klass->implof(self);
  ret = self->get(map, key);
  (void)imdel(self);
  return ret;
}

PUBLIC void ImIMap_SetKeyPolicy(register void *const map, register enum DataPolicy const policy) {
  register struct ImIMap *self = imnew(ImIMap, 0u);
  register struct ImClass *klass = imclass(map);
  klass->implof(self);
  self->set_key_policy(map, policy);
  (void)imdel(self);
}

PUBLIC void ImIMap_SetValPolicy(register void *const map, register enum DataPolicy const policy) {
  register struct ImIMap *self = imnew(ImIMap, 0u);
  register struct ImClass *klass = imclass(map);
  klass->implof(self);
  self->set_val_policy(map, policy);
  (void)imdel(self);
}

PUBLIC void ImIMap_AddOrReplace(register void *const map, register void const *const key, register void *const value) {
  register struct ImIMap *self = imnew(ImIMap, 0u);
  register struct ImClass *klass = imclass(map);
  klass->implof(self);
  self->add_or_replace(map, key, value);
  (void)imdel(self);
}

PUBLIC void ImIMap_RemoveIfExists(register void *const map, register void const *const key) {
  register struct ImIMap *self = imnew(ImIMap, 0u);
  register struct ImClass *klass = imclass(map);
  klass->implof(self);
  self->remove_if_exists(map, key);
  (void)imdel(self);
}

CLASS(ImIMap) {
  _ImIMap.size = sizeof(struct ImIMap);
  _ImIMap.ctor = __constructor__;
  _ImIMap.dtor = __destructor__;
}
