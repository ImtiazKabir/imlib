#include "imlib/imodlog.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "imlib/ansi.h"

void imodlogv(struct IModLog *logger, unsigned char priority,
    char const *fmt, va_list args) {
  struct IModLogLevel *level = NULL;
  if ((logger->mask & (1u << priority)) == 0u) {
    return;
  }
  for (level = logger->level; level <= &logger->level[LOG_ELEM]; level += 1u) {
    if (level->priority == priority) {
      break;
    }
  }
  if (level > &logger->level[LOG_ELEM]) {
    return;
  }
  printf("%s%s%s", level->pre_bg, level->pre_fg, level->prefix);
  printf("%s ", ANSI_RESET);
  printf("%s%s", level->txt_bg, level->txt_fg);
  vprintf(fmt, args);
  printf("%s", ANSI_RESET);
}

void imodlog(struct IModLog *logger, unsigned char priority, char const *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  imodlogv(logger, priority, fmt, args);
  va_end(args);
}

