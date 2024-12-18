#ifndef IMODLOG_H_
#define IMODLOG_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_ELEM sizeof(size_t)

struct IModLogLevel {
  unsigned char priority;
  char const *prefix;
  char const *pre_bg;
  char const *pre_fg;
  char const *txt_bg;
  char const *txt_fg;
};

struct IModLog {
  size_t mask;
  struct IModLogLevel level[LOG_ELEM];
};

void imodlogv(struct IModLog *logger, unsigned char priority,
    char const *fmt, va_list args);

void imodlog(struct IModLog *logger, unsigned char priority, char const *fmt, ...);

#endif /* !IMODLOG_H_ */
