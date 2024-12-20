#ifndef IMPANIC_H_
#define IMPANIC_H_

#include "imstdinc.h"

#define EQ(stmt,val)                                 \
  if ((stmt) != (val)) {                             \
    impanic("Assertion error: " #stmt " != " #val);  \
  }

#define NEQ(stmt,val)                                 \
  if ((stmt) == (val)) {                             \
    impanic("Assertion error: " #stmt " == " #val);  \
  }

extern char const *trace_target;

PUBLIC void imtrace(void);
PUBLIC void impanic(char const *fmt, ...);

#endif /* !IMPANIC_H_ */
