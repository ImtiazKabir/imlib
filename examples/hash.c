#include "imlib/imerrno.h"
#include "imlib/imlog.h"
#include "imlib/immem.h"
#include "imlib/imoption.h"
#include "imlib/impanic.h"
#include "imlib/imstdinc.h"
#include "imlib/imstr.h"
#include "imlib/map/chainmap.h"
#include "imlib/map/imap.h"
#include "imlib/iiter.h"
#include "imlib/impair.h"

#include <errno.h>
#include <stdlib.h>

PRIVATE void Append(register void *const _pair, register void *const _str) {
  register struct ImPair *const pair = _pair;
  register struct ImStr *const str = _str;
  register struct ImStr *const key = ImPair_KeyView(pair);
  register struct ImStr *const val = ImPair_ValueView(pair);
  
  ImStr_Append(str, ImStr_View(key));
  ImStr_Append(str, ": ");
  ImStr_Append(str, ImStr_View(val));
  ImStr_Append(str, "\r\n");
}

PRIVATE void Start(void) {
  register struct ImChainMap *const map = imnew(ImChainMap, 0u);
  register struct ImStr *const k1 = imnew(ImStr, 0u);
  register struct ImStr *const k2 = imnew(ImStr, 0u);
  register struct ImStr *const v1 = imnew(ImStr, 0u);
  register struct ImStr *const v2 = imnew(ImStr, 0u);

  ImIMap_SetKeyPolicy(map, POLICY_TRANSFER);
  ImIMap_SetValPolicy(map, POLICY_TRANSFER);

  ImStr_Append(k1, "Imtiaz");
  ImStr_Append(v1, "Imlib");
  ImIMap_AddOrReplace(map, k1, v1);

  ImStr_Append(k2, "Ritchie");
  ImStr_Append(v2, "C");
  ImIMap_AddOrReplace(map, k2, v2);

  /*
  {
    register struct ImStr *const k = imnew(ImStr, 0u);
    register struct ImStr *v = NULL;
    ImStr_Append(k, "Imtiaz");
    ImIMap_RemoveIfExists(map, k);
    v = ImOptPtr_Unwrap(ImIMap_Get(map, k2));
    imlog1(LOG_INFO, "%obj", v);
    (void)imdel(k);
  }
  */

  {
    register struct ImStr *const sb = imnew(ImStr, 0u);
    register struct ImCMIter *const iter = imnew(ImCMIter, 1u, PARAM_PTR, map);
    ImIIter_ForEach(iter, Append, sb);
    imlog1(LOG_INFO, "\n%obj", sb);
    (void)imdel(iter);
    (void)imdel(sb);
  }

  (void)imdel(map);
}

PUBLIC int main(register int const argc,
                register char const *const *const argv) {
  (void)argc;
  trace_target = argv[0];
  errno = 0;
  imclrerr();

  Start();

  return EXIT_SUCCESS;
}
