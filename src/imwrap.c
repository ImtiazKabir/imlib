#include "imlib/imwrap.h"

#include "imlib/immem.h"
#include <string.h>

#include "imlib/imclass_prot.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"

PRIVATE char *__dupstr__(register char const *const src) {
  return strcpy(imalloct("String", (strlen(src) + 1u) * sizeof(char)), src);
}

PRIVATE void __destructor__(register void *const self) { (void)self; }

#define IM_DEFINE_WRAP(klass, type, param, fmt)                                \
  PUBLIC struct klass *klass##_Construct(register type const val) {            \
    return imnew(klass, 1u, param, val);                                       \
  }                                                                            \
  PUBLIC void klass##_Destroy(register struct klass *self) { imdel(self); }    \
  PRIVATE void __##klass##_constructor__(register void *const _self,           \
                                         register struct ImParams *args) {     \
    register struct klass *const self = _self;                                 \
    if (ImParams_Match(args, 1u, param) == IM_FALSE) {                         \
      impanic("%s\n", "Constructor of " #klass " takes a single " #param);     \
    }                                                                          \
    ImParams_Extract(args, &self->val);                                        \
  }                                                                            \
  PRIVATE void __##klass##_clone_assign__(register void *const _self,          \
                                          register void const *const _from) {  \
    register struct klass *const self = _self;                                 \
    register struct klass const *const from = _from;                           \
    self->val = from->val;                                                     \
  }                                                                            \
                                                                               \
  PRIVATE int __##klass##_compare__(register void const *const _a,             \
                                    register void const *const _b) {           \
    register struct klass const *const a = _a;                                 \
    register struct klass const *const b = _b;                                 \
    register int const cmp = (int)(a->val - b->val);                           \
    if (a->val == b->val) {                                                    \
      return cmp;                                                              \
    } else if (cmp != 0) {                                                     \
      return cmp;                                                              \
    } else if (a->val > b->val) {                                              \
      return 1;                                                                \
    } else {                                                                   \
      return -1;                                                               \
    }                                                                          \
  }                                                                            \
                                                                               \
  PRIVATE size_t __##klass##_hash__(register void const *const _self) {        \
    register struct klass const *const self = _self;                           \
    return (size_t)(self->val);                                                \
  }                                                                            \
                                                                               \
  PRIVATE char *__##klass##_tostr__(register void const *const _self) {        \
    register struct klass const *const self = _self;                           \
    auto char buf[16u] = {0};                                                  \
                                                                               \
    (void)sprintf(buf, fmt, self->val);                                        \
    return __dupstr__(buf);                                                    \
  }                                                                            \
                                                                               \
  CLASS(klass) {                                                               \
    _##klass.size = sizeof(struct klass);                                      \
    _##klass.ctor = __##klass##_constructor__;                                 \
    _##klass.dtor = __destructor__;                                            \
    _##klass.clone = __##klass##_clone_assign__;                               \
    _##klass.assign = __##klass##_clone_assign__;                              \
    _##klass.compare = __##klass##_compare__;                                  \
    _##klass.hash = __##klass##_hash__;                                        \
    _##klass.tostr = __##klass##_tostr__;                                      \
  }

IM_DEFINE_WRAP(ImInt, int, PARAM_INT, "%d")
IM_DEFINE_WRAP(ImShort, short, PARAM_SHORT, "%d")
IM_DEFINE_WRAP(ImLong, long, PARAM_LONG, "%ld")
IM_DEFINE_WRAP(ImFloat, float, PARAM_FLOAT, "%f")
IM_DEFINE_WRAP(ImDouble, double, PARAM_DOUBLE, "%f")
IM_DEFINE_WRAP(ImChar, char, PARAM_CHAR, "%c")
IM_DEFINE_WRAP(ImUint, unsigned int, PARAM_UNSIGNED, "%u")
IM_DEFINE_WRAP(ImUshort, unsigned short, PARAM_UNSIGNED_SHORT, "%u")
IM_DEFINE_WRAP(ImULong, unsigned long, PARAM_UNSIGNED_LONG, "%lu")
IM_DEFINE_WRAP(ImUChar, unsigned char, PARAM_UNSIGNED_CHAR, "%c")
