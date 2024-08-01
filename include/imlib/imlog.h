#ifndef IMLOG_H_
#define IMLOG_H_

#include "imstdinc.h"
#include <stdarg.h>
#include <stdio.h>

/* clang-format off */
#define imlogf(level, fp, fmt)                                                  imlogfcol(level, fp, __FILE__, __LINE__, fmt)
#define imlogf1(level, fp, fmt, arg1)                                           imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1)
#define imlogf2(level, fp, fmt, arg1, arg2)                                     imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2)
#define imlogf3(level, fp, fmt, arg1, arg2, arg3)                               imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3)
#define imlogf4(level, fp, fmt, arg1, arg2, arg3, arg4)                         imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4)
#define imlogf5(level, fp, fmt, arg1, arg2, arg3, arg4, arg5)                   imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5)
#define imlogf6(level, fp, fmt, arg1, arg2, arg3, arg4, arg5, arg6)             imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define imlogf7(level, fp, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)       imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define imlogf8(level, fp, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

#define imlog(level, fmt)                                                  imlogcol(level, __FILE__, __LINE__, fmt)
#define imlog1(level, fmt, arg1)                                           imlogcol(level, __FILE__, __LINE__, fmt, arg1)
#define imlog2(level, fmt, arg1, arg2)                                     imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2)
#define imlog3(level, fmt, arg1, arg2, arg3)                               imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3)
#define imlog4(level, fmt, arg1, arg2, arg3, arg4)                         imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4)
#define imlog5(level, fmt, arg1, arg2, arg3, arg4, arg5)                   imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5)
#define imlog6(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6)             imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define imlog7(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)       imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define imlog8(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) imlogcol(level, stdout, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
/* clang-format on */

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };
enum {
  LMSK_TRACE = (1 << LOG_TRACE),
  LMSK_DEBUG = (1 << LOG_DEBUG),
  LMSK_INFO = (1 << LOG_INFO),
  LMSK_WARN = (1 << LOG_WARN),
  LMSK_ERROR = (1 << LOG_ERROR),
  LMSK_FATAL = (1 << LOG_FATAL)
};

#define LMSK_NONE 0
#define LMSK_ALL                                                               \
  (LMSK_TRACE | LMSK_DEBUG | LMSK_INFO | LMSK_WARN | LMSK_ERROR | LMSK_FATAL)

PUBLIC void imlogvfbw(unsigned char level, FILE *fp, char const *file, int line,
                      char const *fmt, va_list args);
PUBLIC void imlogvbw(unsigned char level, char const *file, int line,
                     char const *fmt, va_list args);
PUBLIC void imlogfbw(unsigned char level, FILE *fp, char const *file, int line,
                     char const *fmt, ...);
PUBLIC void imlogbw(unsigned char level, char const *file, int line,
                    char const *fmt, ...);

PUBLIC void imlogvfcol(unsigned char level, FILE *fp, char const *file,
                       int line, char const *fmt, va_list args);
PUBLIC void imlogvcol(unsigned char level, char const *file, int line,
                      char const *fmt, va_list args);
PUBLIC void imlogfcol(unsigned char level, FILE *fp, char const *file, int line,
                      char const *fmt, ...);
PUBLIC void imlogcol(unsigned char level, char const *file, int line,
                     char const *fmt, ...);

PUBLIC void imlogsetmsk(unsigned char levelmsk);
PUBLIC void imlogsetmin(unsigned char level);

PUBLIC unsigned char imloggetmsk(void);

PUBLIC void imlogaddmsk(unsigned char levelmsk);
PUBLIC void imlogclrmsk(unsigned char levelmsk);

#endif /* IMLOG_H_ */
