#ifndef IMCLASS_PROT_H_
#define IMCLASS_PROT_H_

#include <stdarg.h>
#include <stddef.h>

#include "imparam.h"
#include "imstdinc.h"

struct ImClass {
  void (*class_init)(void);
  char const *const type;
  size_t size;

  struct ImClass *super_class;
  void (*super_params)(struct ImParams *sup_args, struct ImParams *self_args);

  void (*ctor)(void *self, struct ImParams *args);

  /*************************** rule of three *********************************/
  void (*dtor)(void *self);
  void (*clone)(void *self, void const *from);
  void (*assign)(void *self, void const *from);
  int (*compare)(void const *a, void const *b);
  /***************************************************************************/

  char *(*tostr)(register void const *const self);
};

#define CLASS(k)                                                               \
  PRIVATE void __##k##_Init__(void);                                           \
  static struct ImClass _##k = {__##k##_Init__,                                \
                                "CLASS(" #k ")",                               \
                                0u,                                            \
                                NULL,                                          \
                                NULL,                                          \
                                NULL,                                          \
                                NULL,                                          \
                                NULL,                                          \
                                NULL,                                          \
                                NULL,                                          \
                                NULL};                                         \
  struct ImClass *const k = &_##k;                                             \
  PRIVATE void __##k##_Init__(void)

#endif /* !IMCLASS_PROT_H_ */
