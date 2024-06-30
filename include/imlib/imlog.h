#ifndef IMLOG_H_
#define IMLOG_H_

#include "imstdinc.h"
#include <stdarg.h>
#include <stdio.h>

/* clang-format off */
#ifdef LOG_NO_COLOR
#define imlogf(level, fmt)                                                  _imlogf(level, fp, ____FILE____, ____LINE____, fmt)
#define imlogf1(level, fmt, arg1)                                           _imlogf(level, fp, ____FILE____, ____LINE____, fmt, arg1)
#define imlogf2(level, fmt, arg1, arg2)                                     _imlogf(level, fp, __FILE__, __LINE__, fmt, arg1, arg2)
#define imlogf3(level, fmt, arg1, arg2, arg3)                               _imlogf(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3)
#define imlogf4(level, fmt, arg1, arg2, arg3, arg4)                         _imlogf(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4)
#define imlogf5(level, fmt, arg1, arg2, arg3, arg4, arg5)                   _imlogf(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5)
#define imlogf6(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6)             _imlogf(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define imlogf7(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)       _imlogf(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define imlogf8(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) _imlogf(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

#define imlog(level, fmt)                                                  _imlog(level, __FILE__, __LINE__, fmt)
#define imlog1(level, fmt, arg1)                                           _imlog(level, __FILE__, __LINE__, fmt, arg1)
#define imlog2(level, fmt, arg1, arg2)                                     _imlog(level, __FILE__, __LINE__, fmt, arg1, arg2)
#define imlog3(level, fmt, arg1, arg2, arg3)                               _imlog(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3)
#define imlog4(level, fmt, arg1, arg2, arg3, arg4)                         _imlog(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4)
#define imlog5(level, fmt, arg1, arg2, arg3, arg4, arg5)                   _imlog(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5)
#define imlog6(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6)             _imlog(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define imlog7(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)       _imlog(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define imlog8(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) _imlog(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
#else /* !LOG_NO_COLOR */

#define imlogf(level, fmt)                                                  _imlogfcol(level, fp, __FILE__, __LINE__, fmt)
#define imlogf1(level, fmt, arg1)                                           _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1)
#define imlogf2(level, fmt, arg1, arg2)                                     _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2)
#define imlogf3(level, fmt, arg1, arg2, arg3)                               _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3)
#define imlogf4(level, fmt, arg1, arg2, arg3, arg4)                         _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4)
#define imlogf5(level, fmt, arg1, arg2, arg3, arg4, arg5)                   _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5)
#define imlogf6(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6)             _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define imlogf7(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)       _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define imlogf8(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) _imlogfcol(level, fp, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

#define imlog(level, fmt)                                                  _imlogcol(level, __FILE__, __LINE__, fmt)
#define imlog1(level, fmt, arg1)                                           _imlogcol(level, __FILE__, __LINE__, fmt, arg1)
#define imlog2(level, fmt, arg1, arg2)                                     _imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2)
#define imlog3(level, fmt, arg1, arg2, arg3)                               _imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3)
#define imlog4(level, fmt, arg1, arg2, arg3, arg4)                         _imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4)
#define imlog5(level, fmt, arg1, arg2, arg3, arg4, arg5)                   _imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5)
#define imlog6(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6)             _imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define imlog7(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)       _imlogcol(level, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define imlog8(level, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) _imlogcol(level, stdout, __FILE__, __LINE__, fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
#endif /* LOG_NO_COLOR */
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

PUBLIC void imlogvf(unsigned char level, FILE *fp, char const *file, int line,
                    char const *fmt, va_list args);
PUBLIC void imlogv(unsigned char level, char const *file, int line,
                   char const *fmt, va_list args);
PUBLIC void _imlogf(unsigned char level, FILE *fp, char const *file, int line,
                    char const *fmt, ...);
PUBLIC void _imlog(unsigned char level, char const *file, int line,
                   char const *fmt, ...);

PUBLIC void imlogvfcol(unsigned char level, FILE *fp, char const *file,
                       int line, char const *fmt, va_list args);
PUBLIC void imlogvcol(unsigned char level, char const *file, int line,
                      char const *fmt, va_list args);
PUBLIC void _imlogfcol(unsigned char level, FILE *fp, char const *file,
                       int line, char const *fmt, ...);
PUBLIC void _imlogcol(unsigned char level, char const *file, int line,
                      char const *fmt, ...);

PUBLIC void imlogsetmsk(unsigned char levelmsk);
PUBLIC void imlogsetmin(unsigned char level);

PUBLIC unsigned char imloggetmsk(void);

PUBLIC void imlogaddmsk(unsigned char levelmsk);
PUBLIC void imlogclrmsk(unsigned char levelmsk);

#endif /* IMLOG_H_ */
