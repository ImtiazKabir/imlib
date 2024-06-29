/**
 * Memory allocation and deallocation interface
 */

#ifndef IMMEM_H_
#define IMMEM_H_

#include <stdlib.h>

#include "imclass.h"
#include "imstdinc.h"

#define E4C_NOKEYWORDS
#include "e4c.h"
#include "imerrno.h"

E4C_DECLARE_EXCEPTION(NotImMemoryException);
E4C_DECLARE_EXCEPTION(NotAClassException);

enum ImMemErr {
  IMMEM_OK = IM_OK,
  IMERR_NOT_ENOUGH_MEM,
  IMERR_NOT_IMMEM,
  IMERR_NOT_A_CLASS
};

/**
 * Allocate `nbytes` of memory with the type hints of `type`
 *
 * \param type type hint of the block
 * \param nbytes the size of memory in bytes
 * \returns pointer to allocated memory or NULL if allocation fails
 * \raises MemoryException if allocation fails
 *
 * \sa imalloc
 * \sa imfree
 */
PUBLIC void *imalloct(char const *type, size_t nbytes);

/**
 * Allocate `nbytes` of memory with the type hints of `Any`
 *
 * \param nbytes the size of memory in bytes
 * \returns pointer to allocated memory or NULL if allocation fails
 * \raises MemoryException if allocation fails
 *
 * \sa imalloct
 * \sa imfree
 */
PUBLIC void *imalloc(size_t nbytes);
PUBLIC void *imrealloc(void *client_data, size_t nbytes);
PUBLIC int imfree(void *client_data);

PUBLIC size_t imsize(void *client_data);
PUBLIC char const *imtype(void *client_data);
PUBLIC struct ImClass const *imclass(void const *client_data);
PUBLIC ImBool imisclass(void const *client_data);

#endif /* IMMEM_H_ */
