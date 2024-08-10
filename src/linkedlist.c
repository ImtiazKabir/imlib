#include "imlib/list/linkedlist.h"

#include <stddef.h>
#include <stdlib.h>

#include "imlib/imclass_prot.h"
#include "imlib/imlog.h"
#include "imlib/immem.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"
#include "imlib/imstr.h"
#include "imlib/list/list.h"

struct LLNode {
  void *data;
  struct LLNode *prev;
  struct LLNode *next;
  enum DataPolicy policy;
};

PRIVATE enum DataPolicy
__GetPolicyFromUnsigned__(register unsigned const policy) {
  if ((policy == POLICY_BORROW) || (policy == POLICY_TRANSFER)) {
    return policy;
  }
  return POLICY_CLONE;
}

PRIVATE void __LLNode_Constructor__(register void *const _self,
                                    register struct ImParams *const args) {
  register struct LLNode *const self = _self;
  auto void *data = NULL;
  auto unsigned policy = 0u;

  if (ImParams_Match(args, 2u, PARAM_PTR, PARAM_UNSIGNED) == IM_FALSE) {
    impanic("%s\n", "ImLLNode ctor expects (void *, int)");
  }

  ImParams_Extract(args, &data, &policy);

  self->policy = __GetPolicyFromUnsigned__(policy);

  if ((self->policy == POLICY_BORROW) || (self->policy == POLICY_TRANSFER)) {
    self->data = data;
  } else {
    self->data = imclone(data);
  }
}

PRIVATE void __LLNode_Destructor__(register void *const _self) {
  register struct LLNode *const self = _self;
  if ((self->policy == POLICY_CLONE) || (self->policy == POLICY_TRANSFER)) {
    (void)imdel(self->data);
    self->data = NULL;
  }
}

CLASS(LLNode) {
  _LLNode.size = sizeof(struct LLNode);
  _LLNode.ctor = __LLNode_Constructor__;
  _LLNode.dtor = __LLNode_Destructor__;
}

struct ImLinkedList {
  struct LLNode *head;
  struct LLNode *tail;
  size_t length;
  enum DataPolicy current_policy;
};

PRIVATE void __Constructor__(register void *const _self,
                             register struct ImParams *const args) {
  register struct ImLinkedList *const self = _self;
  auto unsigned policy = 0u;

  if (ImParams_Match(args, 0u) != IM_FALSE) {
    self->current_policy = POLICY_CLONE;
  } else if (ImParams_Match(args, 1u, PARAM_UNSIGNED) != IM_FALSE) {
    ImParams_Extract(args, &policy);
    self->current_policy = __GetPolicyFromUnsigned__(policy);
  } else {
    impanic("%s\n", "ImLinkedList ctor takes (void) or (unsigned)");
  }
}

PRIVATE void __DeleteFromFront__(register struct ImLinkedList *const self) {
  if (self->length == 1u) {
    (void)imdel(self->head);
    self->length = 0u;
    self->head = NULL;
    self->tail = NULL;
  } else if (self->length > 1u) {
    register struct LLNode *new_head = NULL;
    new_head = self->head->next;

    (void)imdel(self->head);
    self->length -= 1u;
    self->head = new_head;
    self->head->prev = NULL;
  }
}

PRIVATE void __Destructor__(register void *const _self) {
  register struct ImLinkedList *const self = _self;
  while (self->length != 0u) {
    __DeleteFromFront__(self);
  }
}

PRIVATE void __SetPolicy__(register void *const _self,
                           register enum DataPolicy const policy) {
  register struct ImLinkedList *const self = _self;
  self->current_policy = policy;
}

PRIVATE void __PushBack__(register void *const _self,
                          register void const *data) {
  register struct ImLinkedList *const self = _self;
  register struct LLNode *const new_tail =
      imnew(LLNode, 2u, PARAM_PTR, data, PARAM_UNSIGNED,
            (unsigned)self->current_policy);
  if (self->head == NULL) {
    self->head = new_tail;
  } else if (self->head->next == NULL) {
    self->head->next = new_tail;
    new_tail->prev = self->head;
  }
  self->tail = new_tail;
  self->length += 1u;
}

PRIVATE char *__ToStr__(register void const *const _self) {
  register struct ImLinkedList const *const self = _self;
  register struct ImStr *const str = imnew(ImStr, 0u);
  register char *ret = NULL;
  register struct LLNode const *node = NULL;

  ImStr_Append(str, "[");

  node = self->head;
  while (node != NULL) {
    register char *const data_str = imtostr(node->data);
    ImStr_Append(str, data_str);
    (void)imfree(data_str);
    if (node->next != NULL) {
      ImStr_Append(str, ", ");
    }
    node = node->next;
  }

  ImStr_Append(str, "]");
  ret = imtostr(str);

  (void)imdel(str);
  return ret;
}

PRIVATE void __InterfaceImplementation__(register void *const interface) {
  if (imisof(interface, ImIList) != IM_FALSE) {
    register struct ImIList *const list_interface = interface;
    list_interface->push_back = __PushBack__;
    list_interface->set_policy = __SetPolicy__;
  } else {
    impanic("ImLinkedList does not implement %s\n", imtype(interface));
  }
}

CLASS(ImLinkedList) {
  _ImLinkedList.size = sizeof(struct ImLinkedList);
  _ImLinkedList.ctor = __Constructor__;
  _ImLinkedList.dtor = __Destructor__;
  _ImLinkedList.tostr = __ToStr__;
  _ImLinkedList.implof = __InterfaceImplementation__;
}
