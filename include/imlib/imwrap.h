#ifndef IMWRAP_H_
#define IMWRAP_H_

#include "imclass.h"
#include "imstdinc.h"

#define IM_DECLARE_WRAP(klass, type)                                           \
  struct klass {                                                               \
    type val;                                                                  \
  };                                                                           \
  extern struct ImClass *const klass;                                          \
  PUBLIC struct klass *klass##_Construct(type val);                            \
  PUBLIC void klass##_Destroy(struct klass *self);

IM_DECLARE_WRAP(ImInt, int)
IM_DECLARE_WRAP(ImShort, short)
IM_DECLARE_WRAP(ImLong, long)
IM_DECLARE_WRAP(ImFloat, float)
IM_DECLARE_WRAP(ImDouble, double)
IM_DECLARE_WRAP(ImChar, char)
IM_DECLARE_WRAP(ImUint, unsigned int)
IM_DECLARE_WRAP(ImUshort, unsigned short)
IM_DECLARE_WRAP(ImULong, unsigned long)
IM_DECLARE_WRAP(ImUChar, unsigned char)

#endif /* !IMWRAP_H_ */
