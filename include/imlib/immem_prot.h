#ifndef IMMEM_PROT_H_
#define IMMEM_PROT_H_

#include <stddef.h>

#include "imclass.h"
#include "imstdinc.h"

/*
 * BlockHeader
 * -----------------
 *                  +---------------------+
 *     base addr -> |       allockey      |
 *                  +---------------------+
 *                  |      hint/klass     |
 *                  +---------------------+
 *                  | size of client data |
 *                  +---------------------+
 *   client addr -> |          .          |
 *                  |          .          |
 *                  |          .          |
 *                  +---------------------+
 *
 * allockey is used to indicate whether allocated pointer is obtained from imlib
 * if it is 314159265, it is an ImClass
 * else if it is 271828182, it is a regular data
 * else it is not allocated by immem
 */

#define CLASS_ALLOC_KEY 314159265u
#define DATA_ALLOC_KEY 271828182u

struct BlockHeader {
  union block_type {
    char const *hint;
    struct ImClass *klass;
  } type;
  size_t nbytes;
  size_t allockey;
};

PROTECTED void *_imalloc_c(struct ImClass *klass);

#endif /* !IMMEM_PROT_H_ */
