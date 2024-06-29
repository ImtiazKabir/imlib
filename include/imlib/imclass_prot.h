#ifndef IMCLASS_PROT_H_
#define IMCLASS_PROT_H_

#include <stdarg.h>
#include <stddef.h>

struct ImClass {
  char const *const type; /* has to be first for immem type union */
  size_t const size;      /* same as immem size nbytes */
  struct ImClass const *const super_class;

  void (*const ctor)(void *self, va_list args);

  /*************************** rule of three *********************************/
  void (*const dtor)(void *self);
  void (*const clone)(void *self, void const *from);
  void (*const assign)(void *self, void const *from);
  int (*const compare)(void const *a, void const *b);
  /***************************************************************************/

  char *(*const tostr)(register void const *const self);
};

#endif /* !IMCLASS_PROT_H_ */
