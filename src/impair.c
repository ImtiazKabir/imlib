#include "imlib/impair.h"

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/imstdinc.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"

struct ImPair {
  void *key;
  void *val;
  enum DataPolicy key_policy;
  enum DataPolicy val_policy;
};

PRIVATE enum DataPolicy
__GetPolicyFromUnsigned__(register unsigned const policy) {
  if ((policy == POLICY_BORROW) || (policy == POLICY_TRANSFER)) {
    return policy;
  }
  return POLICY_CLONE;
}

PRIVATE void __Init_Key__(register struct ImPair *const self, register void *const key) {
  if ((self->key_policy == POLICY_BORROW) || (self->key_policy == POLICY_TRANSFER)) {
    self->key = key;
  } else {
    self->key = imclone(key);
  }
}

PRIVATE void __Init_Val__(register struct ImPair *const self, register void *const value) {
  if ((self->val_policy == POLICY_BORROW) || (self->val_policy == POLICY_TRANSFER)) {
    self->val = value;
  } else {
    self->val = imclone(value);
  }
}

PRIVATE void __Init__(
  register struct ImPair *const self, 
  register void *const key, register void *const value,
  register enum DataPolicy const key_policy, 
  register enum DataPolicy const value_policy
) {
  self->key_policy = key_policy;
  self->val_policy = value_policy;

  __Init_Key__(self, key);
  __Init_Val__(self, value);
}

PRIVATE void __Deinit_Key__(register struct ImPair *const self) {
  if ((self->key_policy == POLICY_CLONE) || (self->key_policy == POLICY_TRANSFER)) {
    (void)imdel(self->key);
    self->key = NULL;
  }
}

PRIVATE void __Deinit_Val__(register struct ImPair *const self) {
  if ((self->val_policy == POLICY_CLONE) || (self->val_policy == POLICY_TRANSFER)) {
    (void)imdel(self->val);
    self->val = NULL;
  }
}

PRIVATE void __Deinit__(struct ImPair *self) {
  __Deinit_Key__(self);
  __Deinit_Val__(self);
}

PRIVATE void __Constructor__(register void *const self,
                             register struct ImParams *args) {
  auto void *key = NULL;
  auto void *val = NULL;
  unsigned key_policy = 0u;
  unsigned val_policy = 0u;

  if (ImParams_Match(
    args, 4u, PARAM_PTR, PARAM_PTR, PARAM_UNSIGNED, PARAM_UNSIGNED
  ) == IM_FALSE) {
    impanic("%s\n", "ImPair Constructor takes (void *, void *, DataPolicy, DataPolicy)");
  }

  ImParams_Extract(args, &key, &val, &key_policy, &val_policy);
  __Init__(self, key, val, __GetPolicyFromUnsigned__(key_policy), __GetPolicyFromUnsigned__(val_policy));
}

PRIVATE void __Destructor__(register void *const self) { __Deinit__(self); }

PUBLIC void ImPair_SetKey(register struct ImPair *const self, register void *const key) {
  if (self->key != NULL) {
    __Deinit_Key__(self);
  }
  __Init_Key__(self, key);
}

PUBLIC void ImPair_SetValue(register struct ImPair *const self, register void *const value) {
  if (self->val != NULL) {
    __Deinit_Val__(self);
  }
  __Init_Val__(self, value);
}

PUBLIC void ImPair_SetKeyWithPolicy(register struct ImPair *const self,
                                    register void *const key,
                                    register enum DataPolicy const policy) {
  if (self->key != NULL) {
    __Deinit_Key__(self);
  }
  self->key_policy = policy;
  __Init_Key__(self, key);
}

PUBLIC void ImPair_SetValueWithPolicy(register struct ImPair *const self,
                                      register void *const value,
                                      register enum DataPolicy const policy) {
  if (self->val != NULL) {
    __Deinit_Val__(self);
  }
  self->val_policy = policy;
  __Init_Val__(self, value);
}

PUBLIC void *ImPair_KeyView(struct ImPair const *self) {
  return self->key;
}

PUBLIC void *ImPair_ValueView(struct ImPair const *self) {
  return self->val;
}

CLASS(ImPair) {
  _ImPair.size = sizeof(struct ImPair);
  _ImPair.ctor = __Constructor__;
  _ImPair.dtor = __Destructor__;
}


