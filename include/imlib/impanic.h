#ifndef IMPANIC_H_
#define IMPANIC_H_

#include "imstdinc.h"

extern char const *trace_target;

PUBLIC void imtrace(void);
PUBLIC void impanic(char const *fmt, ...);

#endif /* !IMPANIC_H_ */
