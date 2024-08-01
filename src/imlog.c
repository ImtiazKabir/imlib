#include "imlib/imlog.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "imlib/imstdinc.h"

static unsigned char log_levelmsk = LMSK_ALL;

static char const *level_strings[] = {"TRACE", "DEBUG", "INFO",
                                      "WARN",  "ERROR", "FATAL"};
static char const *level_colors[] = {"\x1b[94m", "\x1b[36m", "\x1b[32m",
                                     "\x1b[33m", "\x1b[31m", "\x1b[35m"};

PUBLIC void imlogvfbw(unsigned char level, FILE *fp, char const *file, int line,
                      char const *fmt, va_list args) {
  auto time_t rawtime = {0};
  register struct tm const *timeinfo = NULL;

  if ((level > LOG_FATAL) || ((log_levelmsk & (1 << level)) == 0)) {
    return;
  }

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  (void)fprintf(fp, "%02d:%02d:%02d %-5s %s:%d: ", timeinfo->tm_hour,
                timeinfo->tm_min, timeinfo->tm_sec, level_strings[level], file,
                line);
  (void)vfprintf(fp, fmt, args);
  (void)fprintf(fp, "\n");
}

PUBLIC void imlogvbw(unsigned char level, char const *file, int line,
                     char const *fmt, va_list args) {
  imlogvfbw(level, stdout, file, line, fmt, args);
}

PUBLIC void imlogfbw(unsigned char level, FILE *fp, char const *file, int line,
                     char const *fmt, ...) {
  auto va_list args = {0};
  va_start(args, fmt);
  imlogvfbw(level, fp, file, line, fmt, args);
  va_end(args);
}

PUBLIC void imlogbw(unsigned char level, char const *file, int line,
                    char const *fmt, ...) {
  auto va_list args = {0};
  FILE *fp = level < LMSK_WARN ? stdout : stderr;
  va_start(args, fmt);
  imlogvfbw(level, fp, file, line, fmt, args);
  va_end(args);
}

PUBLIC void imlogvfcol(unsigned char level, FILE *fp, char const *file,
                       int line, char const *fmt, va_list args) {
  auto time_t rawtime = {0};
  register struct tm const *timeinfo = NULL;

  if ((level > LOG_FATAL) || ((log_levelmsk & (1 << level)) == 0)) {
    return;
  }

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  (void)fprintf(fp, "%02d:%02d:%02d\x1b[0m %s%-5s \x1b[90m%s:%d:\x1b[0m ",
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
                level_colors[level], level_strings[level], file, line);
  (void)vfprintf(fp, fmt, args);
  (void)fprintf(fp, "\n");
}

PUBLIC void imlogvcol(unsigned char level, char const *file, int line,
                      char const *fmt, va_list args) {
  imlogvfcol(level, stdout, file, line, fmt, args);
}

PUBLIC void imlogfcol(unsigned char level, FILE *fp, char const *file, int line,
                      char const *fmt, ...) {
  auto va_list args = {0};
  va_start(args, fmt);
  imlogvfcol(level, fp, file, line, fmt, args);
  va_end(args);
}

PUBLIC void imlogcol(unsigned char level, char const *file, int line,
                     char const *fmt, ...) {
  auto va_list args = {0};
  FILE *fp = level < LMSK_WARN ? stdout : stderr;
  va_start(args, fmt);
  imlogvfcol(level, fp, file, line, fmt, args);
  va_end(args);
}

PUBLIC void imlogsetmsk(unsigned char levelmsk) { log_levelmsk = levelmsk; }
PUBLIC void imlogsetmin(unsigned char level) {
  log_levelmsk = (unsigned char)(((unsigned char)-1) << level);
}

PUBLIC unsigned char imloggetmsk(void) { return log_levelmsk; }

PUBLIC void imlogaddmsk(unsigned char levelmsk) { log_levelmsk |= levelmsk; }
PUBLIC void imlogclrmsk(unsigned char levelmsk) { log_levelmsk &= ~levelmsk; }
