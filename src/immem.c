#include "imlib/immem.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/imerrno.h"
#include "imlib/imlog.h"
#include "imlib/immem_prot.h"
#include "imlib/imstdinc.h"

PRIVATE struct BlockHeader *__imalloc_common__(register size_t const nbytes) {
  register struct BlockHeader *const header =
      calloc(1u, nbytes + sizeof(struct BlockHeader));

  if (header == NULL) {
    imerr(IMERR_NOT_ENOUGH_MEM, "Could not allocate memory");
    return NULL;
  }
  header->nbytes = nbytes;
  return header;
}

PUBLIC void *imalloct(register char const *const type,
                      register size_t const nbytes) {
  /* Return a typed block of nbytes */

  register struct BlockHeader *header = NULL;

  header = __imalloc_common__(nbytes);
  if (header == NULL) {
    return NULL;
  }

  header->allockey = DATA_ALLOC_KEY;
  header->type.hint = type;

  return (void *)(((char *)header) + sizeof(struct BlockHeader));
}

PUBLIC void *imalloc(register size_t const nbytes) {
  return imalloct("Any", nbytes);
}

PROTECTED void *_imalloc_c(register struct ImClass *const klass) {
  /* Return a newable memory region of nbytes.
   * This function is not supposed to be used by client directly.
   * Use imnew instead.
   */

  register size_t nbytes = 0u;
  register struct BlockHeader *header = NULL;

  nbytes = klass->size;

  header = __imalloc_common__(nbytes);
  if (header == NULL) {
    return NULL;
  }

  header->allockey = CLASS_ALLOC_KEY;
  header->type.klass = klass;
  return (void *)(((char *)header) + sizeof(struct BlockHeader));
}

PRIVATE struct BlockHeader *
__get_header__(register void const *const client_data) {
  return (struct BlockHeader *)(((char const *)client_data) -
                                sizeof(struct BlockHeader));
}

PRIVATE ImBool __is_immem__(register struct BlockHeader const *const header) {
  if ((header->allockey != DATA_ALLOC_KEY) &&
      (header->allockey != CLASS_ALLOC_KEY)) {
    return IM_FALSE;
  }
  return IM_TRUE;
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
  if (__is_immem__(prev_header) == IM_FALSE) {
    return NULL;
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
    register struct BlockHeader *const header = __get_header__(client_data);

    if (__is_immem__(header) == IM_FALSE) {
      imerr(IMERR_NOT_IMMEM, "Data was not allocated by imlib");
      return imerrno();
    }

    (void)memset(header, 0, sizeof(struct BlockHeader) + header->nbytes);
    free((void *)header);
  }
  return IM_OK;
}

PUBLIC size_t imsize(register void *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);

  if (__is_immem__(header) == IM_FALSE) {
    imerr(IMERR_NOT_IMMEM, "Data was not allocated by imlib");
    return 0u;
  }
  return header->nbytes;
}

PUBLIC char const *imtype(register void *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);

  if (__is_immem__(header) == IM_FALSE) {
    imerr(IMERR_NOT_IMMEM, "Data was not allocated by imlib");
    return NULL;
  }

  if (header->allockey == DATA_ALLOC_KEY) {
    return header->type.hint;
  } else {
    register struct ImClass const *const klass = imclass(client_data);
    return klass->type;
  }
}

PUBLIC struct ImClass *imclass(register void const *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);

  if (__is_immem__(header) == IM_FALSE) {
    imerr(IMERR_NOT_IMMEM, "Data was not allocated by imlib");
    return NULL;
  }

  if (header->allockey != CLASS_ALLOC_KEY) {
    imerr(IMERR_NOT_A_CLASS, "Data not a class");
    return NULL;
  }

  if (header->type.klass->class_init != NULL) {
    header->type.klass->class_init();
    header->type.klass->class_init = NULL;
  }

  return header->type.klass;
}

PUBLIC ImBool imisclass(register void const *const client_data) {
  register struct BlockHeader const *const header = __get_header__(client_data);
  return header->allockey == CLASS_ALLOC_KEY;
}
