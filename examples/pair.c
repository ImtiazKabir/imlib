#include "imlib/imerrno.h"
#include "imlib/imlog.h"
#include "imlib/immem.h"
#include "imlib/impair.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"
#include "imlib/imstr.h"
#include "imlib/imwrap.h"

#include <errno.h>
#include <stdlib.h>

PRIVATE void Start(void) {
  register struct ImPair *const pair =
      imnew(ImPair, 4u, PARAM_PTR, NULL, PARAM_PTR, NULL, PARAM_UNSIGNED,
            POLICY_TRANSFER, PARAM_UNSIGNED, POLICY_TRANSFER);

  ImPair_SetKey(pair, ImInt_Construct(41));
  ImPair_SetValue(pair, imnew(ImStr, 0u));

  ImStr_Append(ImPair_ValueView(pair), "Imtiaz Kabir");

  imlog1(LOG_INFO, "%obj", pair);

  (void)imdel(pair);
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
