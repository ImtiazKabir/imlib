#ifndef IMERRNO_H_
#define IMERRNO_H_

#include "imlib/imstdinc.h"

#define IM_OK_MSG "No error"

enum Err { IM_OK, IMERR_ILLEGAL_ARG };

PUBLIC void imerr(int errcode, char const *errmsg);
PUBLIC int imerrno(void);
PUBLIC char const *imerrmsg(void);
PUBLIC void imclrerr(void);
PUBLIC void imperror(char const *str);

#endif /* IMERRNO_H_ */
