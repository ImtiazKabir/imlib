#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"

#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "imlib/imerrno.h"
#include "imlib/immem.h"
#include "imlib/immem_prot.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"

PRIVATE char *__dupstr__(register char const *const src) {
  return strcpy(calloc(strlen(src) + 1u, sizeof(*src)), src);
}

PUBLIC struct ImClass *imsup(register struct ImClass *const klass) {
  if (klass->class_init != NULL) {
    klass->class_init();
    klass->class_init = NULL;
  }

  return klass->super_class;
}

PUBLIC ImBool imisof(register void const *const self,
                     register struct ImClass const *const klass) {
  register struct ImClass *this_class = imclass(self);
  while (this_class != NULL) {
    if (this_class == klass) {
      return IM_TRUE;
    }
    this_class = this_class->super_class;
  }
  return IM_FALSE;
}

PUBLIC char *imtostr(register void const *const self) {
  register struct ImClass const *const klass = imclass(self);

  if (klass->tostr != NULL) {
    return klass->tostr(self);
  } else {
    enum { mx_addr_sz = 50 };
    auto char address[mx_addr_sz] = {0};
    (void)sprintf(address, "%p", self);
    address[mx_addr_sz - 1u] = '\0';
    return __dupstr__(address);
  }
}

PUBLIC size_t imhash(register void const *const self) {
  register struct ImClass const *const klass = imclass(self);
  if (klass->hash != NULL) {
    return klass->hash(self);
  } else {
    return 0;
  }
}

PUBLIC int imcomp(register void const *const a, register void const *const b) {
  if (a == b) {
    return 0;
  } else {
    register struct ImClass const *const klass1 = imclass(a);
    register struct ImClass const *const klass2 = imclass(b);
    if (klass1 != klass2) {
      return INT_MAX;
    } else if (klass1->compare != NULL) {
      return klass1->compare(a, b);
    } else {
      return (int)((char *)a - (char *)b);
    }
  }
}

PRIVATE int __call_ctor__(register void *const self,
                          register struct ImClass *const klass,
                          register struct ImParams *args) {
  /* recursive helper of calling base ctor first, then self ctor */
  register struct ImClass *super_class = NULL;
  auto struct ImParams super_args = {0};

  if (klass->ctor == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No constructor");
    return imerrno();
  }

  super_class = imsup(klass);
  if (super_class != NULL) {
    if (klass->super_params == NULL) {
      imerr(IMERR_POORLY_DEFINED_CLASS, "No super_params()");
      return imerrno();
    }

    klass->super_params(&super_args, args);

    if (__call_ctor__(self, super_class, &super_args) != IM_OK) {
      return imerrno();
    }
  }
  klass->ctor(self, args);
  return IM_OK;
}

PRIVATE void __init_ancestry_line__(struct ImClass *const klass) {
  if (klass == NULL) {
    return;
  }
  if (klass->class_init != NULL) {
    klass->class_init();
    klass->class_init = NULL;
  }
  __init_ancestry_line__(klass->super_class);
}

PUBLIC void *imnew(struct ImClass *const klass, ...) {
  register void *self = NULL;
  auto va_list list = {0};
  auto struct ImParams args = {0};
  register size_t len = 0u;

  __init_ancestry_line__(klass);
  self = _imalloc_c(klass);

  va_start(list, klass);
  len = va_arg(list, size_t);
  if (len != 0u) {
    ImParams_VPush(&args, len, list);
  }
  va_end(list);

  if (__call_ctor__(self, klass, &args) != IM_OK) {
    return NULL;
  }

  return self;
}

PRIVATE int __call_dtor__(register void *const self,
                          register struct ImClass *const klass) {
  /* recursive helper of calling base dtor first, then self dtor */
  if (klass == NULL) {
    return IM_OK;
  }

  if (klass->dtor == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No destructor");
    return imerrno();
  }

  klass->dtor(self);
  __call_dtor__(self, klass->super_class);
  return IM_OK;
}

PUBLIC int imdel(register void *const self) {
  if (self == NULL) {
    return IM_OK;
  } else {
    register struct ImClass *const klass = imclass(self);
    if (__call_dtor__(self, klass) != IM_OK) {
      return imerrno();
    }
    return imfree(self);
  }
}

PRIVATE int __call_clone__(register void const *const self,
                           register struct ImClass *const klass,
                           register void *const ret) {
  /* recursive helper of calling base clone first, then self clone */
  if (klass == NULL) {
    return IM_OK;
  }

  if (klass->clone == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No clone");
    return imerrno();
  }
  __call_clone__(self, klass->super_class, ret);
  klass->clone(ret, self);
  return IM_OK;
}

PUBLIC void *imclone(void const *self) {
  register struct ImClass *const klass = imclass(self);
  register void *ret = NULL;

  ret = _imalloc_c(klass);
  if (__call_clone__(self, klass, ret) != IM_OK) {
    return NULL;
  }

  return ret;
}

PRIVATE int __call_assign__(register void const *const self,
                            register struct ImClass *const klass,
                            register void *const ret) {
  /* recursive helper of calling base clone first, then self clone */
  if (klass == NULL) {
    return IM_OK;
  }
  if (klass->assign == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No assign");
    return imerrno();
  }
  __call_assign__(self, klass->super_class, ret);
  klass->assign(ret, self);
  return IM_OK;
}

PUBLIC void const *imassign(void *self, void const *from) {
  register struct ImClass *const klass = imclass(self);
  if (__call_assign__(from, klass, self) != IM_OK) {
    return NULL;
  }
  return from;
}
