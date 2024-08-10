#ifndef IMLIB_LIST_H_
#define IMLIB_LIST_H_

#include "../imclass.h"
#include "../imstdinc.h"

enum DataPolicy { POLICY_CLONE, POLICY_TRANSFER, POLICY_BORROW };

struct ImIList {
  void (*set_policy)(void *list, enum DataPolicy policy);
  void (*push_back)(void *list, void const *data);
  /*void *(*pop_front)(void *data);*/
};

extern struct ImClass *const ImIList;

PUBLIC void ImIList_SetPolicy(void *list, enum DataPolicy policy);
PUBLIC void ImIList_PushBack(void *list, void const *data);
/*PUBLIC void *ImIList_PopFront(void *list);*/

#endif /* IMLIB_LIST_H_ */
