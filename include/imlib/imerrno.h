#ifndef IMERRNO_H_
#define IMERRNO_H_

#include "imlib/imstdinc.h"

#define IM_OK_MSG "No error"

enum Err { IM_OK, IMERR_ILLEGAL_ARG };

/* Set the thread-local error code and message */
PUBLIC void imerr(int errcode, char const *errmsg);

/* Get the current thread-local error code */
PUBLIC int imerrno(void);

/* Get the current thread-local error message */
PUBLIC char const *imerrmsg(void);

/* Clear the error code and message */
PUBLIC void imclrerr(void);

#endif /* IMERRNO_H_ */
