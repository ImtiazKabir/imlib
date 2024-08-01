#include <stdbool.h>
#include <stdint.h>

#include "imerror.h"
#include "immem.h"
#include "impanic.h"
#include "imstdinc.h"

#define RESULT_TRY(dest, tag, res, ret)                                        \
  do {                                                                         \
    struct tag _result_##tag##_try_at_##__LINE__ = res;                        \
    if (_result_##tag##_try_at_##__LINE__.err) {                               \
      return REINTERPRET_CAST(struct ret, _result_##tag##_try_at_##__LINE__;)  \
    }                                                                          \
    dest = _result_##tag##_try_at_##__LINE__.value;                            \
  } while (0)

#define RESULT_OK(tag) tag##_Ok
#define RESULT_ERR(tag) tag##_Err
#define RESULT_IS_OK(tag) tag##_IsOk
#define RESULT_IS_ERR(tag) tag##_IsErr
#define RESULT_UNWRAP(tag) tag##_Unwrap
#define RESULT_EXPECT(tag) tag##_Expect
#define RESULT_UNWRAP_OR(tag) tag##_UnwrapOr
#define RESULT_UNWRAP_ERR(tag) tag##_UnwrapErr

#define IM_DECLARE_RESULT(tag, type)                                           \
  struct tag {                                                                 \
    type value;                                                                \
    struct ImError *err;                                                       \
  };                                                                           \
  struct tag RESULT_OK(tag)(type);                                             \
  struct tag RESULT_ERR(tag)(struct ImError * err);                            \
  int RESULT_IS_OK(tag)(struct tag const *);                                   \
  int RESULT_IS_ERR(tag)(struct tag const *);                                  \
  type RESULT_UNWRAP(tag)(struct tag const *);                                 \
  type RESULT_EXPECT(tag)(struct tag const *, char const *);                   \
  type RESULT_UNWRAP_OR(tag)(struct tag const *, type);                        \
  struct ImError *RESULT_UNWRAP_ERR(tag)(struct tag const *);

#define IM_DEFINE_RESULT(tag, type)                                            \
  struct tag RESULT_OK(tag)(type value) {                                      \
    struct tag res = {0};                                                      \
    res.value = value;                                                         \
    return res;                                                                \
  }                                                                            \
  struct tag RESULT_ERR(tag)(struct ImError * err) {                           \
    struct tag res = {0};                                                      \
    res.err = err;                                                             \
    return res;                                                                \
  }                                                                            \
  int RESULT_IS_OK(tag)(struct tag const *res) { return res->err == NULL; }    \
  int RESULT_IS_ERR(tag)(struct tag const *res) { return res->err != NULL; }   \
  type RESULT_UNWRAP(tag)(struct tag const *res) {                             \
    if (RESULT_IS_ERR(tag)(res)) {                                             \
      impanic("Attempted to unwrap empty Result of type " #type                \
              ". Instead had error %s: %s\n",                                  \
              imtype(res->err), res->err->desc);                               \
    }                                                                          \
    return res->value;                                                         \
  }                                                                            \
  type RESULT_EXPECT(tag)(struct tag const *res, char const *message_on_err) { \
    if (RESULT_IS_ERR(tag)(res))                                               \
      impanic("%s\n", message_on_err);                                         \
    return res->value;                                                         \
  }                                                                            \
  type RESULT_UNWRAP_OR(tag)(struct tag const *res, type else_val) {           \
    if (RESULT_IS_ERR(tag)(res)) {                                             \
      return else_val;                                                         \
    }                                                                          \
    return res->value;                                                         \
  }                                                                            \
  struct ImError *RESULT_UNWRAP_ERR(tag)(struct tag const *res) {              \
    if (RESULT_IS_ERR(tag)(res)) {                                             \
      impanic("%s\n",                                                          \
              "Attempted to unwrap Ok Result of type " #type " for error.");   \
    }                                                                          \
    return res->err;                                                           \
  }
