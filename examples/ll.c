#include "imlib/list/linkedlist.h"
#include <stdlib.h>

#include "imlib/imlog.h"
#include "imlib/imoption.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imresult.h"
#include "imlib/imstdinc.h"
#include "imlib/imwrap.h"
#include "imlib/iiter.h"
#include "imlib/list/ilist.h"

PRIVATE void Summation(register void *const num, register void *const sum) {
  *(int *)sum += *(int *)num;
}

PRIVATE ImBool Predicate(register void const *const data) {
  register int const num = *(int *)data;
  return num > 8;
}

PRIVATE void Test(void) {
  register struct ImLinkedList *const list = imnew(ImLinkedList, 0u);
  auto int sum = 0;

  ImIList_SetPolicy(list, POLICY_TRANSFER);

  /* should fail */
  ImResInt_UnwrapOr(ImIList_Insert(list, 0u, ImInt_Construct(-5)), 0);

  ImIList_Append(list, ImInt_Construct(10));
  ImIList_Insert(list, 0u, ImInt_Construct(5));
  ImIList_Insert(list, 1u, ImInt_Construct(15));

  imlog1(LOG_INFO, "list = %obj", list);

  {
    register void const *const key = ImInt_Construct(15);
    imlog2(LOG_DEBUG, "indexOf(%obj) = %lu", key,
           ImOptULong_Unwrap(ImIList_IndexOf(list, key)));
    (void)imdel((void *)key);
  }

  ImResInt_Unwrap(ImIList_Remove(list, 2u));
  imlog1(LOG_INFO, "list = %obj", list);

  {
    register struct ImLLIter *const iter = imnew(ImLLIter, 1u, PARAM_PTR, list);
    ImIIter_ForEach(iter, Summation, &sum);
    imlog1(LOG_INFO, "sum(list) = %d", sum);
    (void)imdel(iter);
  }

  ImIList_Retain(list, Predicate);
  imlog1(LOG_INFO, "list = %obj", list);

  (void)imdel(list);
}

PUBLIC int main(register int const argc,
                register char const *const *const argv) {
  (void)argc;
  trace_target = argv[0];

  Test();

  return EXIT_SUCCESS;
}
