#ifndef IMLIB_I_LIST_H_
#define IMLIB_I_LIST_H_

#include "../imclass.h"
#include "../imerror.h"
#include "../imresult.h"
#include "../imstdinc.h"

enum DataPolicy { POLICY_CLONE, POLICY_TRANSFER, POLICY_BORROW };

struct ImIList {
  size_t (*len)(void *list);
  struct ImResPtr (*get)(void *list, size_t index);
  void (*set_policy)(void *list, enum DataPolicy policy);
  struct ImResInt (*insert)(void *list, size_t index, void *data);
  void (*append)(void *list, void const *data);
  struct ImResInt (*remove)(void *list, size_t index);
  struct ImOptULong (*index_of)(void *list, void const *data);
  void (*retain)(void *list, ImBool (*predicate)(void const *));
};

extern struct ImClass *const ImIList;

PUBLIC size_t ImIList_Len(void *list);
PUBLIC struct ImResPtr ImIList_Get(void *list, size_t index);
PUBLIC void ImIList_SetPolicy(void *list, enum DataPolicy policy);
PUBLIC struct ImResInt ImIList_Insert(void *list, size_t index, void *data);
PUBLIC void ImIList_Append(void *list, void const *data);
PUBLIC struct ImResInt ImIList_Remove(void *list, size_t index);
PUBLIC struct ImOptULong ImIList_IndexOf(void *list, void const *data);
PUBLIC void ImIList_Retain(void *list, ImBool (*predicate)(void const *));

#endif /* IMLIB_I_LIST_H_ */
