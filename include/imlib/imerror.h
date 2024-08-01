#ifndef IMERROR_H_
#define IMERROR_H_

#include <stdarg.h>

#include "imclass.h"
#include "imparam.h"
#include "imstdinc.h"

struct ImError {
  int code;
  char *desc;
};

extern struct ImClass *const ImError;

PUBLIC void ErrorCtor(void *self, struct ImParams *args);

PUBLIC void ErrorDtor(void *self);

#define IM_DECLARE_ERROR(name)                                                 \
  struct name {                                                                \
    struct ImError err;                                                        \
  };                                                                           \
  extern struct ImClass *const name;

#define IM_DEFINE_ERROR(name, code, desc)                                      \
  PRIVATE void __##name##_super_params__(                                      \
      register struct ImParams *const sup_args,                                \
      register struct ImParams *const self_args) {                             \
    register char const *m = NULL;                                             \
    if (self_args->len > 0u) {                                                 \
      m = self_args->params[0u].value.pointer_rep;                             \
    } else {                                                                   \
      m = desc;                                                                \
    }                                                                          \
    ImParams_Push(sup_args, 2u, PARAM_INT, code, PARAM_PTR, m);                \
  }                                                                            \
                                                                               \
  CLASS(name) {                                                                \
    _##name.size = sizeof(struct name);                                        \
    _##name.super_class = ImError;                                             \
    _##name.super_params = __##name##_super_params__;                          \
    _##name.ctor = ErrorCtor;                                                  \
    _##name.dtor = ErrorDtor;                                                  \
  }

#endif /* !IMERROR_H_ */
