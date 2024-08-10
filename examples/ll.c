#include "imlib/list/linkedlist.h"
#include <stdlib.h>

#include "imlib/imlog.h"
#include "imlib/immem.h"
#include "imlib/impanic.h"
#include "imlib/imstdinc.h"
#include "imlib/imwrap.h"
#include "imlib/list/list.h"

PRIVATE void PushTest(void) {
  register struct ImLinkedList *const list = imnew(ImLinkedList, 0u);

  ImIList_SetPolicy(list, POLICY_TRANSFER);

  ImIList_PushBack(list, ImInt_Construct(20));
  ImIList_PushBack(list, ImInt_Construct(30));

  imlog1(LOG_DEBUG, "%obj", list);

  (void)imdel(list);
}

PUBLIC int main(register int const argc,
                register char const *const *const argv) {
  (void)argc;
  trace_target = argv[0];

  PushTest();
  return EXIT_SUCCESS;
}
