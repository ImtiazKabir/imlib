#ifndef IMCLASS_H_
#define IMCLASS_H_

#include <stddef.h>
#include <stdio.h>

#include "imstdinc.h"

#include "imerrno.h"

enum { IMCLASS_OK = IM_OK, IMERR_POORLY_DEFINED_CLASS };

struct ImClass;

PUBLIC struct ImClass *imsup(struct ImClass *klass);

PUBLIC ImBool imisof(void const *self, struct ImClass const *klass);

PUBLIC char *imtostr(void const *self);
PUBLIC size_t imhash(void const *self);
PUBLIC int imcomp(void const *a, void const *b);

PUBLIC void *imnew(struct ImClass *klass, ...);

/***************************** rule of three *********************************/
PUBLIC int imdel(void *self);
PUBLIC void *imclone(void const *self);
PUBLIC void const *imassign(void *self, void const *from);
/*****************************************************************************/

#endif /* !IMCLASS_H_ */
