#include "imlib/ansi.h"
#include "imlib/imodlog.h"

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

  return 0;
}


