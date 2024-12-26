#ifndef IMLIB_I_ITER_H_
#define IMLIB_I_ITER_H_

#include "imclass.h"
#include "imoption.h"
#include "imstdinc.h"

struct ImIIter {
  struct ImOptPtr (*next)(void *iter);
  void (*reset)(void *iter);
};

extern struct ImClass *const ImIIter;

PUBLIC struct ImOptPtr ImIIter_Next(void *iter);
PUBLIC void ImIIter_Reset(void *iter);

PUBLIC void ImIIter_ForEach(void *iter, void (*func)(void *, void *),
                            void *ret);

#endif /* IMLIB_I_ITER_H_ */
