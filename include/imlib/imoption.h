#include <stdbool.h>
#include <stdint.h>

#include "impanic.h"
#include "imstdinc.h"

#define OPTION_TRY(dest, tag, opt, ret)                                        \
  do {                                                                         \
    struct tag _option_##tag##_try_at_##__LINE__ = opt;                        \
    if (_option_##tag##_try_at_##__LINE__.some == 0) {                         \
      return REINTERPRET_CAST(struct ret, _option_##tag##_try_at_##__LINE__);  \
    }                                                                          \
    dest = _option_##tag##_try_at_##__LINE__.value;                            \
  } while (0)

#define OPTION_SOME(tag) tag##_Some
#define OPTION_NONE(tag) tag##_None
#define OPTION_IS_SOME(tag) tag##_IsSome
#define OPTION_IS_NONE(tag) tag##_IsNone
#define OPTION_UNWRAP(tag) tag##_Unwrap
#define OPTION_EXPECT(tag) tag##_Expect
#define OPTION_UNWRAP_OR(tag) tag##_UnwrapOr

#define IM_DECLARE_OPTION(tag, type)                                           \
  struct tag {                                                                 \
    type value;                                                                \
    int some;                                                                  \
  };                                                                           \
  struct tag OPTION_SOME(tag)(type);                                           \
  struct tag OPTION_NONE(tag)(void);                                           \
  int OPTION_IS_SOME(tag)(struct tag const);                                   \
  int OPTION_IS_NONE(tag)(struct tag const);                                   \
  type OPTION_UNWRAP(tag)(struct tag const);                                   \
  type OPTION_EXPECT(tag)(struct tag const, char const *);                     \
  type OPTION_UNWRAP_OR(tag)(struct tag const, type);

#define IM_DEFINE_OPTION(tag, type)                                            \
  struct tag OPTION_SOME(tag)(type value) {                                    \
    struct tag opt = {0};                                                      \
    opt.value = value;                                                         \
    opt.some = 1;                                                              \
    return opt;                                                                \
  }                                                                            \
  struct tag OPTION_NONE(tag)(void) {                                          \
    struct tag opt = {0};                                                      \
    opt.some = 0;                                                              \
    return opt;                                                                \
  }                                                                            \
  int OPTION_IS_SOME(tag)(struct tag const opt) { return opt.some != 0; }      \
  int OPTION_IS_NONE(tag)(struct tag const opt) { return opt.some == 0; }      \
  type OPTION_UNWRAP(tag)(struct tag const opt) {                              \
    if (OPTION_IS_NONE(tag)(opt)) {                                            \
      impanic("%s\n", "Attempted to unwrap empty Option of type " #type);      \
    }                                                                          \
    return opt.value;                                                          \
  }                                                                            \
  type OPTION_EXPECT(tag)(struct tag const opt, char const *message_on_none) { \
    if (OPTION_IS_NONE(tag)(opt)) {                                            \
      impanic("%s\n", message_on_none);                                        \
    }                                                                          \
    return opt.value;                                                          \
  }                                                                            \
  type OPTION_UNWRAP_OR(tag)(struct tag const opt, type else_val) {            \
    if (OPTION_IS_NONE(tag)(opt)) {                                            \
      return else_val;                                                         \
    }                                                                          \
    return opt.value;                                                          \
  }

#ifndef IMOPTION_H_
#define IMOPTION_H_
IM_DECLARE_OPTION(ImOptInt, int)
IM_DECLARE_OPTION(ImOptShort, short)
IM_DECLARE_OPTION(ImOptLong, long)
IM_DECLARE_OPTION(ImOptFloat, float)
IM_DECLARE_OPTION(ImOptDouble, double)
IM_DECLARE_OPTION(ImOptChar, char)
IM_DECLARE_OPTION(ImOptUInt, unsigned int)
IM_DECLARE_OPTION(ImOptUShort, unsigned short)
IM_DECLARE_OPTION(ImOptULong, unsigned long)
IM_DECLARE_OPTION(ImOptUChar, unsigned char)
IM_DECLARE_OPTION(ImOptPtr, void *)
#endif /* !IMOPTION_H_ */
