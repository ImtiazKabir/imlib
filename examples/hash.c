#include "imlib/imstdinc.h"
#include "imlib/impanic.h"
#include "imlib/imerrno.h"
#include "imlib/immem.h"
#include "imlib/imstr.h"

#include <stdlib.h>
#include <errno.h>


PRIVATE void Start(void) {
  register struct ImStr *const str = imnew(ImStr, 0u);
  
  ImStr_Append(str, "imtiaz");
  (void)printf("%lu\n", imhash(str));
  
  imdel(str);
}


PUBLIC int main(register int const argc, register char const *const *const argv) {
  (void)argc;
  trace_target = argv[0];
  errno = 0;
  imclrerr();

  Start();

  return EXIT_SUCCESS;
}

