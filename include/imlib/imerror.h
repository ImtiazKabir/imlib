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

#define IM_DECLARE_ERROR(name)                                                 \
  struct name {                                                                \
    struct ImError err;                                                        \
  };                                                                           \
  extern struct ImClass *const name;

#define IM_DEFINE_ERROR(name, code, desc)                                      \
  PRIVATE void __##name##_ctor__(register void *const self,                    \
                                 register struct ImParams *const args) {       \
    (void)self;                                                                \
    (void)args;                                                                \
  }                                                                            \
  PRIVATE void __##name##_dtor__(register void *const self) { (void)self; }    \
  PRIVATE void __##name##_super_params__(                                      \
      register struct ImParams *const sup_args,                                \
      register struct ImParams *const self_args) {                             \
    if (ImParams_Match(self_args, 1u, PARAM_PTR) != IM_FALSE) {                \
      auto char const *arg_desc = NULL;                                        \
      ImParams_Extract(self_args, &arg_desc);                                  \
      (void)ImParams_Push(sup_args, 2u, PARAM_INT, code, PARAM_PTR, arg_desc); \
    } else if (ImParams_Match(self_args, 0u) != IM_FALSE) {                    \
      (void)ImParams_Push(sup_args, 2u, PARAM_INT, code, PARAM_PTR, desc);     \
    } else {                                                                   \
      impanic("%s\n", "Any subclass of ImError has constructor parameters "    \
                      "(char const *) or (void)");                             \
    }                                                                          \
  }                                                                            \
                                                                               \
  CLASS(name) {                                                                \
    _##name.size = sizeof(struct name);                                        \
    _##name.super_class = ImError;                                             \
    _##name.super_params = __##name##_super_params__;                          \
    _##name.ctor = __##name##_ctor__;                                          \
    _##name.dtor = __##name##_dtor__;                                          \
  }

#endif /* !IMERROR_H_ */
