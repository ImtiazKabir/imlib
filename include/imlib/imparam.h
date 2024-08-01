#ifndef IMPARAM_H_
#define IMPARAM_H_

#include <stdarg.h>
#include <stddef.h>

#define MAX_PARAM_LEN 16u

struct ImParams {
  size_t len;
  struct {
    enum {
      PARAM_INT,
      PARAM_SHORT,
      PARAM_LONG,
      PARAM_FLOAT,
      PARAM_DOUBLE,
      PARAM_CHAR,
      PARAM_UNSIGNED,
      PARAM_UNSIGNED_SHORT,
      PARAM_UNSIGNED_LONG,
      PARAM_UNSIGNED_CHAR,
      PARAM_PTR
    } type;

    union {
      int int_rep;
      short short_rep;
      long long_rep;
      float float_rep;
      double double_rep;
      char char_rep;
      unsigned int unsigned_rep;
      unsigned short unsigned_short_rep;
      unsigned long unsigned_long_rep;
      unsigned char unsigned_char_rep;
      void *pointer_rep;
    } value;
  } params[MAX_PARAM_LEN];
};

struct ImParams *ImParams_VPush(struct ImParams *self, size_t len,
                                va_list list);

struct ImParams *ImParams_Push(struct ImParams *self, size_t len, ...);

#endif /* !IMPARAM_H_ */
