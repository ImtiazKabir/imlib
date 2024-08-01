/**
 * Memory allocation and deallocation interface
 */

#ifndef IMMEM_H_
#define IMMEM_H_

#include <stdlib.h>

#include "imclass.h"
#include "imstdinc.h"

#include "imerrno.h"

enum {
  IMMEM_OK = IM_OK,
  IMERR_NOT_ENOUGH_MEM,
  IMERR_NOT_IMMEM,
  IMERR_NOT_A_CLASS
};

PUBLIC void *imalloct(char const *type, size_t nbytes);
PUBLIC void *imalloc(size_t nbytes);
PUBLIC void *imrealloc(void *client_data, size_t nbytes);
PUBLIC int imfree(void *client_data);

PUBLIC size_t imsize(void *client_data);
PUBLIC char const *imtype(void *client_data);
PUBLIC struct ImClass *imclass(void const *client_data);
PUBLIC ImBool imisclass(void const *client_data);

#endif /* IMMEM_H_ */
