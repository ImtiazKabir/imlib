#include <stdio.h>
#include <stdlib.h>

#include "imlib/imclass.h"
#include "imlib/immem.h"
#include "imlib/imstdinc.h"
#include "imlib/imstr.h"

#include <string.h>
#include <time.h>

#define E4C_NOKEYWORDS
#include "e4c.h"

#include "imlib/imlog.h"

PRIVATE void __strtest__(void) {
  register struct ImStr *str1 = imnew(ImStr, "this is good");
  register struct ImStr *str2 = imnew(ImStr, "Hello there");
  ImStr_AppendFmt(str1, " %s\n", ImStr_View(str2));
  (void)imputobj(str1, stdout);
  (void)imputobj(str2, stdout);
  (void)imdel(str1);
  (void)imdel(str2);
}

int main(register int const argc, register char const *const *const argv) {
  (void)argc;
  (void)argv;

  imlogsetmin(LOG_WARN);

  imlog2(LOG_TRACE, "Hello %d %d", 2, 3);
  imlog2(LOG_DEBUG, "Hello %d %d", 2, 3);
  imlog2(LOG_INFO, "Hello %d %d", 2, 3);
  imlog2(LOG_WARN, "Hello %d %d", 2, 3);
  imlog2(LOG_ERROR, "Hello %d %d", 2, 3);
  imlog2(LOG_FATAL, "Hello %d %d", 2, 3);

  return EXIT_SUCCESS;
}
