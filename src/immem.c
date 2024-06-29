#include "imlib/immem.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/imerrno.h"
#include "imlib/immem_prot.h"
#include "imlib/imstdinc.h"

#define E4C_NOKEYWORDS
#include "e4c.h"

E4C_DEFINE_EXCEPTION(
    NotImMemoryException,
    "Either 1) this memory was not allocated by Imlib, 2) it is not "
    "the beginning of allocated memory or 3) it is already freed once",
    RuntimeException);

E4C_DEFINE_EXCEPTION(NotAClassException,
                     "This is not the beginning of a class memory region",
                     RuntimeException);

PRIVATE struct BlockHeader *__imalloc_common__(register size_t const nbytes) {
  register struct BlockHeader *const header =
      calloc(1u, nbytes + sizeof(struct BlockHeader));

  if (header == NULL) {
    imerr(IMERR_NOT_ENOUGH_MEM, "Could not allocate memory");
    E4C_THROW(NotEnoughMemoryException, "Could not allocate memory");
  }
  header->nbytes = nbytes;
  return header;
}

PUBLIC void *imalloct(register char const *const type,
                      register size_t const nbytes) {
  /* Return a typed block of nbytes */

  register struct BlockHeader *header = NULL;

  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { header = __imalloc_common__(nbytes); }
    if (status == -1) {
      return NULL;
    }
  }

  header->allockey = DATA_ALLOC_KEY;
  header->type.hint = type;

  return (void *)(((char *)header) + sizeof(struct BlockHeader));
}

PUBLIC void *imalloc(register size_t const nbytes) {
  return imalloct("Any", nbytes);
}

PROTECTED void *_imalloc_c(register struct ImClass const *const klass) {
  /* Return a newable memory region of nbytes.
   * This function is not supposed to be used by client directly.
   * Use imnew instead.
   */

  register size_t const nbytes = klass->size;
  register struct BlockHeader *header = NULL;

  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { header = __imalloc_common__(nbytes); }
    if (status == -1) {
      return NULL;
    }
  }

  header->allockey = CLASS_ALLOC_KEY;
  header->type.klass = klass;
  return (void *)(((char *)header) + sizeof(struct BlockHeader));
}

PRIVATE struct BlockHeader const *
__get_header__(register void const *const client_data) {
  return (struct BlockHeader const *)(((char const *)client_data) -
                                      sizeof(struct BlockHeader));
}

PRIVATE void __immem_check__(register struct BlockHeader const *const header) {
  if ((header->allockey != DATA_ALLOC_KEY) &&
      (header->allockey != CLASS_ALLOC_KEY)) {
    imerr(IMERR_NOT_IMMEM, "Memory not allocated by ImLib");
    E4C_THROW(NotImMemoryException, NULL);
  }
}

PUBLIC void *imrealloc(register void *const client_data,
                       register size_t const nbytes) {
  register struct BlockHeader const *prev_header = NULL;
  register size_t allockey = 0u;
  register union block_type type = {0};
  register struct BlockHeader *new_header = NULL;

  if (client_data == NULL) {
    return imalloc(nbytes);
  }

  prev_header = __get_header__(client_data);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { __immem_check__(prev_header); }
    if (status != 0) {
      return NULL;
    }
  }

  allockey = prev_header->allockey;
  type = prev_header->type;

  new_header =
      realloc((void *)prev_header, sizeof(struct BlockHeader) + nbytes);
  new_header->allockey = allockey;
  new_header->type = type;
  new_header->nbytes = nbytes;

  return ((char *)new_header) + sizeof(struct BlockHeader);
}

PUBLIC int imfree(register void *const client_data) {
  if (client_data != NULL) {
    register struct BlockHeader const *const header =
        __get_header__(client_data);

    {
      register volatile int status = 0;
      E4C_REUSING_CONTEXT(status, -1) { __immem_check__(header); }
      if (status != 0) {
        return imerrno();
      }
    }

    free((void *)header);
  }
  return IM_OK;
}

PUBLIC size_t imsize(register void *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { __immem_check__(header); }
    if (status != 0) {
      return 0u;
    }
  }
  return header->nbytes;
}

PUBLIC char const *imtype(register void *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { __immem_check__(header); }
    if (status != 0) {
      return NULL;
    }
  }
  if (header->allockey == DATA_ALLOC_KEY) {
    return header->type.hint;
  } else {
    register struct ImClass const *const klass = imclass(client_data);
    return klass->type;
  }
}

PUBLIC struct ImClass const *imclass(register void const *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { __immem_check__(header); }
    if (status != 0) {
      return NULL;
    }
  }

  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) {
      if (header->allockey != CLASS_ALLOC_KEY) {
        E4C_THROW(NotAClassException, NULL);
      }
    }
    if (status != 0) {
      imerr(IMERR_NOT_A_CLASS, "Data not a class");
      return NULL;
    }
  }

  return header->type.klass;
}

PUBLIC ImBool imisclass(register void const *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);
  return header->allockey == CLASS_ALLOC_KEY;
}
