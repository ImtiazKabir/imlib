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

int main(register int const argc, register char const *const *const argv) {
  (void)argc;
  (void)argv;
  imlog(LOG_TRACE, "Hello world!");
  return EXIT_SUCCESS;
}
