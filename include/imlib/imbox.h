#ifndef IMBOX_H_
#define IMBOX_H_

#include <stdarg.h>

#include "imclass.h"
#include "imparam.h"
#include "imstdinc.h"

struct ImBoxMethod {
  /*************************** rule of three *********************************/
  void (*dtor)(void *self);
  void *(*clone)(void const *from);
  void (*assign)(void *self, void const *from);
  /***************************************************************************/

  int (*compare)(void const *a, void const *b);
  char *(*tostr)(void const *self);
};

struct ImBox {
  void *data;
  struct ImBoxMethod method;
};

extern struct ImClass *const ImBox;

#define IM_BOX(data, method)                                                   \
  imnew(ImBox, 2u, PARAM_PTR, data, PARAM_PTR, method)

#endif /* !IMBOX_H_ */
