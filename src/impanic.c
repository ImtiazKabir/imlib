#include "imlib/impanic.h"

#include <execinfo.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "imlib/imlog.h"
#include "imlib/imstdinc.h"
#include "imlib/imerrno.h"


char const *trace_target = "notarget"; PUBLIC void imtrace(void) {
  enum { MAX_STACK_FRAMES = 64 };
  void *stack_traces[MAX_STACK_FRAMES];
  int i, trace_size = 0;
  char **messages = NULL;

  trace_size = backtrace(stack_traces, MAX_STACK_FRAMES);
  messages = backtrace_symbols(stack_traces, trace_size);

  for (i = 0; i < trace_size; ++i) {
    char addr2line_cmd[512] = {0};
    char const *const beg = strstr(messages[i], "+0x");
    char const *const end = strstr(beg, ")");
    char offset[16u] = {0};
    memcpy(offset, beg, end - beg);
    sprintf(addr2line_cmd, "addr2line -s -f -p -e %s %s", trace_target, offset);
    system(addr2line_cmd);
  }
  if (messages) {
    free(messages);
  }
}

PUBLIC void impanic(char const *const fmt, ...) {
  auto va_list args = {0};
  register unsigned char const msk = imloggetmsk();

  imlogsetmin(LOG_TRACE);

  imlogf(LOG_FATAL, stderr, "Program panicked");
  perror("errno");
  imperror("imerrno");
  fprintf(stderr, "Panic message: ");

  va_start(args, fmt);
  (void)vfprintf(stderr, fmt, args);
  va_end(args);

  fprintf(stderr, "\n");

  imlogf(LOG_TRACE, stderr, "");
  imtrace();

  imlogsetmsk(msk);
  exit(EXIT_FAILURE);
}
