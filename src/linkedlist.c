#include "imlib/list/linkedlist.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "imlib/imclass_prot.h"
#include "imlib/immem.h"
#include "imlib/imoption.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"
#include "imlib/imstr.h"
#include "imlib/iiter.h"
#include "imlib/list/ilist.h"

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

PRIVATE void __RemoveFront__(register struct ImLinkedList *const self) {
  register struct LLNode *const node = self->head;

  self->head = node->next;
  if (self->head == NULL) {
    self->tail = NULL;
  } else {
    self->head->prev = NULL;
  }

  (void)imdel(node);

  self->length -= 1u;
}

PRIVATE void __RemoveBack__(register struct ImLinkedList *const self) {
  register struct LLNode *const node = self->tail;

  self->tail = node->prev;
  if (self->tail == NULL) {
    self->head = NULL;
  } else {
    self->tail->next = NULL;
  }

  (void)imdel(node);

  self->length -= 1u;
}

PRIVATE void __Destructor__(register void *const _self) {
  register struct ImLinkedList *const self = _self;
  while (self->length != 0u) {
    __RemoveFront__(self);
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
    self->tail = new_tail;
  } else {
    new_tail->prev = self->tail;
    self->tail->next = new_tail;
    self->tail = new_tail;
  }
  self->length += 1u;
}

PRIVATE void __PushFront__(register struct ImLinkedList *const self,
                           register void const *data) {
  register struct LLNode *const new_head =
      imnew(LLNode, 2u, PARAM_PTR, data, PARAM_UNSIGNED,
            (unsigned)self->current_policy);
  if (self->head == NULL) {
    self->head = new_head;
    self->tail = new_head;
  } else {
    new_head->next = self->head;
    self->head->prev = new_head;
    self->head = new_head;
  }
  self->length += 1u;
}

PRIVATE struct ImResInt __Insert__(register void *const _self,
                                   register size_t const index,
                                   register void *const data) {
  register struct ImLinkedList *const self = _self;
  register struct LLNode *prev_node = NULL;
  register struct LLNode *added_node = NULL;

  if (index >= self->length) {
    auto char msg[70u] = {0};
    if ((self->current_policy == POLICY_TRANSFER) ||
        (self->current_policy == POLICY_CLONE)) {
      (void)imdel(data);
    }
    sprintf(msg, "Index %lu is out of bound for a list of length %lu", index,
            self->length);
    return ImResInt_Err(imnew(IndexOutOfBound, 1u, PARAM_PTR, msg));
  }

  if (index == 0u) {
    __PushFront__(self, data);
    return ImResInt_Ok(0);
  }

  if (index == self->length - 1u) {
    __PushBack__(self, data);
    return ImResInt_Ok(0);
  }

  prev_node = self->head;
  /* clang-format off */
  FOR(size_t i, i = 0u; i < index - 1u; i += 1u, { 
    prev_node = prev_node->next; 
  });
  /* clang-format on */
  added_node = imnew(LLNode, 2u, PARAM_PTR, data, PARAM_UNSIGNED,
                     (unsigned)self->current_policy);
  added_node->next = prev_node->next;
  added_node->prev = prev_node;
  prev_node->next = added_node;

  self->length += 1u;
  return ImResInt_Ok(0);
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

PRIVATE size_t __Len__(register void *const _self) {
  register struct ImLinkedList *const self = _self;
  return self->length;
}

PRIVATE struct ImResPtr __Get__(register void *const _self,
                                register size_t const index) {
  register struct ImLinkedList *const self = _self;
  register struct LLNode *node = NULL;

  if (index >= self->length) {
    auto char msg[70u] = {0};
    sprintf(msg, "Index %lu is out of bound for a list of length %lu", index,
            self->length);
    return ImResPtr_Err(imnew(IndexOutOfBound, 1u, PARAM_PTR, msg));
  }

  node = self->head;
  FOR(size_t i, i = 0u; i < index; i += 1u, { node = node->next; });
  return ImResPtr_Ok(node->data);
}

PRIVATE struct ImResInt __Remove__(register void *const _self,
                                   register size_t const index) {
  register struct ImLinkedList *const self = _self;
  register struct LLNode *node = NULL;

  if (index >= self->length) {
    auto char msg[70u] = {0};
    (void)sprintf(msg, "Index %lu is out of bound for a list of length %lu",
                  index, self->length);
    return ImResInt_Err(imnew(IndexOutOfBound, 1u, PARAM_PTR, msg));
  }

  if (index == 0u) {
    __RemoveFront__(self);
    return ImResInt_Ok(0);
  }

  if (index == self->length - 1u) {
    __RemoveBack__(self);
    return ImResInt_Ok(0);
  }

  node = self->head;
  FOR(size_t i, i = 0u; i < index; i += 1u, { node = node->next; });
  node->prev->next = node->next;
  node->next->prev = node->prev;

  (void)imdel(node);

  self->length -= 1u;

  return ImResInt_Ok(0);
}

PRIVATE struct ImOptULong __IndexOf__(register void *const _self,
                                      register void const *const data) {
  register struct ImLinkedList *const self = _self;
  register struct LLNode const *node = NULL;

  node = self->head;
  FOR(size_t i, i = 0u; i < self->length; i += 1u, {
    if (imcomp(node->data, data) == 0) {
      return ImOptULong_Some(i);
    }
    node = node->next;
  });
  return ImOptULong_None();
}

PRIVATE void __Retain__(register void *const _self,
                        register ImBool (*predicate)(void const *)) {
  register struct ImLinkedList *const self = _self;
  register struct LLNode const *node = NULL;

  node = self->head;
  while (node != NULL) {
    register struct LLNode const *const tmp = node;

    if (predicate(node->data) != IM_FALSE) {
      node = node->next;
      continue;
    }

    if (node->prev == NULL) {
      self->head = node->next;
    } else {
      node->prev->next = node->next;
    }

    if (node->next == NULL) {
      self->tail = node->prev;
    } else {
      node->next->prev = node->prev;
    }

    node = node->next;
    (void)imdel((void *)tmp);
    self->length -= 1u;
  }
}

PRIVATE void __InterfaceImplementation__(register void *const interface) {
  if (imisof(interface, ImIList) != IM_FALSE) {
    register struct ImIList *const list_interface = interface;
    list_interface->len = __Len__;
    list_interface->get = __Get__;
    list_interface->insert = __Insert__;
    list_interface->append = __PushBack__;
    list_interface->set_policy = __SetPolicy__;
    list_interface->remove = __Remove__;
    list_interface->index_of = __IndexOf__;
    list_interface->retain = __Retain__;
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

struct ImLLIter {
  struct LLNode **node;
};

PRIVATE void __ImLLIter_Constructor__(register void *const _self,
                                      register struct ImParams *const args) {
  register struct ImLLIter *const self = _self;
  auto struct ImLinkedList *list = NULL;
  if (ImParams_Match(args, 1u, PARAM_PTR) == IM_FALSE) {
    impanic("%s\n", "ImLLIter ctor takes (void *) as paramter");
  }
  ImParams_Extract(args, &list);
  self->node = &list->head;
}

PRIVATE void __ImLLIter_Destructor__(register void *const self) { (void)self; }

PRIVATE struct ImOptPtr __ImLLIter_Next__(register void *const _self) {
  register struct ImLLIter *const self = _self;
  register struct ImOptPtr ret = ImOptPtr_None();
  if (*self->node == NULL) {
    return ImOptPtr_None();
  }

  ret = ImOptPtr_Some((*self->node)->data);
  self->node = &(*self->node)->next;
  return ret;
}

PRIVATE void __ImLLIter_ForEach__(register void *const _self,
                                  register void (*func)(void *, void *),
                                  register void *const ret) {
  register struct ImLLIter *const self = _self;
  register struct LLNode *node = NULL;

  node = *self->node;
  while (node != NULL) {
    func(node->data, ret);
    node = node->next;
  }
}

PRIVATE void __ImLLIter_Implementation__(register void *const interface) {
  if (imisof(interface, ImIIter) != IM_FALSE) {
    register struct ImIIter *const iter_interface = interface;
    iter_interface->next = __ImLLIter_Next__;
  } else {
    impanic("ImLLIter does not implement %s\n", imtype(interface));
  }
}

CLASS(ImLLIter) {
  _ImLLIter.size = sizeof(struct ImLLIter);
  _ImLLIter.ctor = __ImLLIter_Constructor__;
  _ImLLIter.dtor = __ImLLIter_Destructor__;
  _ImLLIter.implof = __ImLLIter_Implementation__;
}
