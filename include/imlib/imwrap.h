#ifndef IMWRAP_H_
#define IMWRAP_H_

#include "imclass.h"
#include "imstdinc.h"

#define DECLARE_IM_WRAP(klass, type)                                           \
  struct klass {                                                               \
    type val;                                                                  \
  };                                                                           \
  extern struct ImClass *const klass;                                          \
  PUBLIC struct klass *klass##_Construct(type val);                            \
  PUBLIC void klass##_Destroy(struct klass *self);

DECLARE_IM_WRAP(ImInt, int)
DECLARE_IM_WRAP(ImShort, short)
DECLARE_IM_WRAP(ImLong, long)
DECLARE_IM_WRAP(ImFloat, float)
DECLARE_IM_WRAP(ImDouble, double)
DECLARE_IM_WRAP(ImChar, char)
DECLARE_IM_WRAP(ImUint, unsigned int)
DECLARE_IM_WRAP(ImUshort, unsigned short)
DECLARE_IM_WRAP(ImULong, unsigned long)
DECLARE_IM_WRAP(ImUChar, unsigned char)

#endif /* !IMWRAP_H_ */
