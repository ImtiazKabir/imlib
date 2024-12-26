#include "imlib/map/chainmap.h"
#include "imlib/map/imap.h"

#include "imlib/iiter.h"
#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/immem.h"
#include "imlib/imoption.h"
#include "imlib/impair.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"
#include "imlib/list/ilist.h"
#include "imlib/list/linkedlist.h"
#include "imlib/iiter.h"

#include <stdlib.h>

struct ImChainMap {
  struct ImLinkedList **chains;
  unsigned int num_chain;
  size_t len;
  enum DataPolicy key_policy;
  enum DataPolicy val_policy;
};

PRIVATE void __Constructor__(register void *const _self,
                             register struct ImParams *args) {
  register struct ImChainMap *const self = _self;

  if (ImParams_Match(args, 0u) != IM_FALSE) {
    self->num_chain = 23;
  } else if (ImParams_Match(args, 1u, PARAM_UNSIGNED) != IM_FALSE) {
    ImParams_Extract(args, &self->num_chain);
  } else {
    impanic("ImChainMap constructor takes (void) or (unsigned)");
  }

  self->chains = imalloct("Array<ImLinkedList>",
                          self->num_chain * sizeof(struct ImLinkedList *));

  FOR(size_t i, i = 0u; i < self->num_chain; i += 1u, {
    self->chains[i] = imnew(ImLinkedList, 0u);
    ImIList_SetPolicy(self->chains[i], POLICY_TRANSFER);
  });
}

PRIVATE void __Destructor__(register void *const _self) {
  register struct ImChainMap *const self = _self;

  FOR(size_t i, i = 0u; i < self->num_chain; i += 1u, {
    (void)imdel(self->chains[i]);
    self->chains[i] = NULL;
  });

  (void)imfree(self->chains);
  self->chains = NULL;
}

PRIVATE size_t __Len__(register void *const _self) {
  register struct ImChainMap *const self = _self;
  return self->len;
}

PRIVATE void __SetKeyPolicy__(register void *const _self,
                              register enum DataPolicy const policy) {
  register struct ImChainMap *const self = _self;
  self->key_policy = policy;
}

PRIVATE void __SetValPolicy__(register void *const _self,
                              register enum DataPolicy const policy) {
  register struct ImChainMap *const self = _self;
  self->val_policy = policy;
}

PRIVATE struct ImLinkedList *
__GetChainFromKey__(register struct ImChainMap const *const self,
                    register void const *const key) {
  register size_t const hash = imhash(key);
  register size_t const index = hash % self->num_chain;
  return self->chains[index];
}

PRIVATE struct ImOptPtr __GetPair__(register struct ImChainMap *const self,
                                    register void const *const key) {
  register struct ImOptPtr opt = ImOptPtr_None();
  register struct ImLinkedList *const chain = __GetChainFromKey__(self, key);
  register struct ImLLIter *const iter = imnew(ImLLIter, 1u, PARAM_PTR, chain);

  while (IM_TRUE) {
    register struct ImOptPtr const nxt = ImIIter_Next(iter);
    if (ImOptPtr_IsNone(nxt) != IM_FALSE) {
      break;
    } else {
      register struct ImPair *const pair = ImOptPtr_Unwrap(nxt);
      register void *const pkey = ImPair_KeyView(pair);
      if (imcomp(key, pkey) == 0) {
        opt = ImOptPtr_Some(pair);
        break;
      }
    }
  }

  (void)imdel(iter);

  return opt;
}

PRIVATE struct ImOptPtr __Get__(register void *const _self,
                                register void const *const key) {
  register struct ImChainMap *const self = _self;
  register struct ImOptPtr opt = ImOptPtr_None();

  opt = __GetPair__(self, key);

  if (ImOptPtr_IsSome(opt) != IM_FALSE) {
    register struct ImPair *const pair = ImOptPtr_Unwrap(opt);
    register void *const val = ImPair_ValueView(pair);
    opt = ImOptPtr_Some(val);
  }

  return opt;
}

PRIVATE void __AddOrReplace__(register void *const _self,
                              register void const *const key,
                              register void *const val) {
  register struct ImChainMap *const self = _self;
  register struct ImOptPtr const opt = __GetPair__(self, key);

  if (ImOptPtr_IsSome(opt) != IM_FALSE) {
    register struct ImPair *const pair = ImOptPtr_Unwrap(opt);
    ImPair_SetKeyWithPolicy(pair, (void *)key, self->key_policy);
    ImPair_SetValueWithPolicy(pair, val, self->val_policy);
  } else {
    register struct ImLinkedList *const chain = __GetChainFromKey__(self, key);
    register struct ImPair *const pair = imnew(
        ImPair, 4u, PARAM_PTR, key, PARAM_PTR, val, PARAM_UNSIGNED,
        (unsigned)self->key_policy, PARAM_UNSIGNED, (unsigned)self->val_policy);
    ImIList_Append(chain, pair);
    self->len += 1u;
  }
}

PRIVATE void __RemoveIfExists__(register void *const _self,
                                register void const *const key) {
  register struct ImChainMap *const self = _self;
  register struct ImOptPtr const opt = __GetPair__(self, key);

  if (ImOptPtr_IsSome(opt) != IM_FALSE) {
    register struct ImLinkedList *const chain = __GetChainFromKey__(self, key);
    register struct ImPair *const pair = ImOptPtr_Unwrap(opt);
    register size_t const index =
        ImOptULong_Unwrap(ImIList_IndexOf(chain, pair));
    ImIList_Remove(chain, index);
    self->len -= 1u;
  }
}

PRIVATE void __InterfaceImplementation__(register void *const interface) {
  if (imisof(interface, ImIMap) != IM_FALSE) {
    register struct ImIMap *const map_interface = interface;
    map_interface->len = __Len__;
    map_interface->get = __Get__;
    map_interface->remove_if_exists = __RemoveIfExists__;
    map_interface->add_or_replace = __AddOrReplace__;
    map_interface->set_key_policy = __SetKeyPolicy__;
    map_interface->set_val_policy = __SetValPolicy__;
  } else {
    impanic("ImChainMap does not implement %s\n", imtype(interface));
  }
}

CLASS(ImChainMap) {
  _ImChainMap.size = sizeof(struct ImChainMap);
  _ImChainMap.ctor = __Constructor__;
  _ImChainMap.dtor = __Destructor__;
  _ImChainMap.implof = __InterfaceImplementation__;
}

struct ImCMIter {
  struct ImChainMap *map;
  size_t chain_index;
  struct ImLLIter *iter;
};

PRIVATE void __ImCMIter_Constructor__(register void *const _self,
                                      register struct ImParams *const args) {
  register struct ImCMIter *const self = _self;
  auto struct ImChainMap *map = NULL;
  if (ImParams_Match(args, 1u, PARAM_PTR) == IM_FALSE) {
    impanic("%s\n", "ImLLIter ctor takes (void *) as paramter");
  }
  ImParams_Extract(args, &map);

  self->map = map;
  self->chain_index = 0;
  self->iter = NULL;
}

PRIVATE void __ImCMIter_Destructor__(register void *const _self) {
  register struct ImCMIter *const self = _self;
  (void)imdel(self->iter);
}

PRIVATE struct ImOptPtr __ImCMIter_Next__(register void *const _self) {
  register struct ImCMIter *const self = _self;
  register struct ImOptPtr nxt = ImOptPtr_None();

  while (self->chain_index < self->map->num_chain) {
    if (self->iter == NULL) {
      self->iter = imnew(ImLLIter, 1u, PARAM_PTR, self->map->chains[self->chain_index]);
    }
    nxt = ImIIter_Next(self->iter);
    if (ImOptPtr_IsSome(nxt) != IM_FALSE) {
      break;
    }
    self->chain_index += 1u;
    (void)imdel(self->iter);
    self->iter = NULL;
  }

  return nxt;
}

PRIVATE void __ImCMIter_Reset__(register void *const _self) {
  register struct ImCMIter *const self = _self;
  self->chain_index = 0;
  (void)imdel(self->iter);
  self->iter = NULL;
}

PRIVATE void __ImCMIter_Implementation__(register void *const interface) {
  if (imisof(interface, ImIIter) != IM_FALSE) {
    register struct ImIIter *const iter_interface = interface;
    iter_interface->next = __ImCMIter_Next__;
    iter_interface->reset = __ImCMIter_Reset__;
  } else {
    impanic("ImLLIter does not implement %s\n", imtype(interface));
  }
}

CLASS(ImCMIter) {
  _ImCMIter.size = sizeof(struct ImCMIter);
  _ImCMIter.ctor = __ImCMIter_Constructor__;
  _ImCMIter.dtor = __ImCMIter_Destructor__;
  _ImCMIter.implof = __ImCMIter_Implementation__;
}

