#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"

#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define E4C_NOKEYWORDS
#include "e4c.h"

#include "imlib/imerrno.h"
#include "imlib/immem.h"
#include "imlib/immem_prot.h"
#include "imlib/imstdinc.h"

E4C_DEFINE_EXCEPTION(PoorlyDefinedClassException,
                     "Class does not have needed method", RuntimeException);

PRIVATE char *__dupstr__(register char const *const src) {
  return strcpy(calloc(strlen(src) + 1u, sizeof(*src)), src);
}

PUBLIC struct ImClass const *imsup(register struct ImClass const *const klass) {
  return klass->super_class;
}

PUBLIC ImBool imisof(register void const *const self,
                     register struct ImClass const *const klass) {
  register struct ImClass const *this_class = imclass(self);
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

PUBLIC int imputobj(register void const *const self, register FILE *const fp) {
  register char *const str = imtostr(self);
  register int const ret = fputs(str, fp);
  imfree(str);
  return ret;
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

PRIVATE void __call_ctor__(register void *const self,
                           register struct ImClass const *const klass,
                           register va_list args) {
  /* recursive helper of calling base ctor first, then self ctor */
  if (klass == NULL) {
    return;
  }

  if (klass->ctor == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No constructor");
    E4C_THROW(PoorlyDefinedClassException, "No constructor");
  }

  __call_ctor__(self, klass->super_class, args);
  klass->ctor(self, args);
}

PUBLIC void *imnew(struct ImClass const *const klass, ...) {
  register void *self = NULL;
  auto va_list args = {0};

  self = _imalloc_c(klass);
  va_start(args, klass);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) {
      E4C_TRY { __call_ctor__(self, klass, args); }
      E4C_CATCH(PoorlyDefinedClassException) { imfree(self); }
    }
    if (status != 0) {
      return NULL;
    }
  }
  va_end(args);

  return self;
}

PRIVATE void __call_dtor__(register void *const self,
                           register struct ImClass const *const klass) {
  /* recursive helper of calling base dtor first, then self dtor */
  if (klass == NULL) {
    return;
  }

  if (klass->dtor == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No destructor");
    E4C_THROW(PoorlyDefinedClassException, "No destructor");
  }

  __call_dtor__(self, klass->super_class);
  klass->dtor(self);
}

PUBLIC int imdel(register void *const self) {
  register struct ImClass const *const klass = imclass(self);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { __call_dtor__(self, klass); }
    if (status != 0) {
      return imerrno();
    }
  }
  return imfree(self);
}

PRIVATE void __call_clone__(register void const *const self,
                            register struct ImClass const *const klass,
                            register void *const ret) {
  /* recursive helper of calling base clone first, then self clone */
  if (klass == NULL) {
    return;
  }

  if (klass->clone == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No clone");
    E4C_THROW(PoorlyDefinedClassException, "No clone");
  }
  __call_clone__(self, klass->super_class, ret);
  klass->clone(ret, self);
}

PUBLIC void *imclone(void const *self) {
  register struct ImClass const *const klass = imclass(self);
  register void *ret = NULL;
  ret = _imalloc_c(klass);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { __call_clone__(self, klass, ret); }
    if (status != 0) {
      return NULL;
    }
  }
  return ret;
}

PRIVATE void __call_assign__(register void const *const self,
                             register struct ImClass const *const klass,
                             register void *const ret) {
  /* recursive helper of calling base clone first, then self clone */
  if (klass == NULL) {
    return;
  }
  if (klass->assign == NULL) {
    imerr(IMERR_POORLY_DEFINED_CLASS, "No assign");
    E4C_THROW(PoorlyDefinedClassException, "No assign");
  }
  __call_assign__(self, klass->super_class, ret);
  klass->assign(ret, self);
}

PUBLIC void const *imassign(void *self, void const *from) {
  register struct ImClass const *const klass = imclass(self);
  {
    register volatile int status = 0;
    E4C_REUSING_CONTEXT(status, -1) { __call_assign__(from, klass, self); }
    if (status != 0) {
      return NULL;
    }
  }
  return from;
}
