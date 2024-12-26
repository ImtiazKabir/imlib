#include "imlib/ansi.h"
#include "imlib/imodlog.h"
#include "imlib/imstr.h"
#include "imlib/imparam.h"

enum {
  YESS,
  HAHA,
  OHNO
};

struct IModLog mylogger = {
  (size_t)-1,
  {
    {YESS, "[YES]", ANSI_BG_WHITE, ANSI_FG_BLACK, ANSI_BG_DEFAULT, ANSI_FG_DEFAULT},
    {HAHA, "[HAHA]", ANSI_BG_DEFAULT, ANSI_FG_YELLOW, ANSI_BG_DEFAULT, ANSI_FG_DEFAULT},
    {OHNO, "[OHNO]", ANSI_BG_DEFAULT, ANSI_FG_RED, ANSI_BG_DEFAULT, ANSI_FG_DEFAULT}
  }
};

extern int main(void) {
  mylogger.mask &= ~(1u << YESS);

  imodlog(&mylogger, YESS, "Yess world\n");
  imodlog(&mylogger, HAHA, "Haha world %d\n", 2);
  imodlog(&mylogger, OHNO, "Ohno world\n");

  {
    struct ImStr *const str1 = imnew(ImStr, 1u, PARAM_PTR, "Imodlog");
    struct ImStr *const str2 = imnew(ImStr, 1u, PARAM_PTR, "Im Module Log");
    ImStr_AppendFmt(str1, " means %obj", str2);
    imodlog(&mylogger, HAHA, "%obj\n", str1);
    (void)imdel(str1);
    (void)imdel(str2);
  }

  return 0;
}


