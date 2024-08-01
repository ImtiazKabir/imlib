#include "imlib/imparam.h"

#include <stdarg.h>

struct ImParams *ImParams_VPush(register struct ImParams *const self,
                                register size_t const len,
                                register va_list list) {
  register size_t i = 0u;
  if (self == NULL) {
    return NULL;
  }

  for (i = 0u; i < len; i += 1u) {
    register unsigned type = 0;
    if (self->len >= MAX_PARAM_LEN) {
      return NULL;
    }
    self->len += 1u;

    type = va_arg(list, unsigned);
    self->params[self->len - 1u].type = type;
    switch (type) {
    case PARAM_INT: {
      self->params[self->len - 1u].value.int_rep = va_arg(list, int);
      break;
    }
    case PARAM_SHORT: {
      self->params[self->len - 1u].value.short_rep = va_arg(list, int);
      break;
    }
    case PARAM_LONG: {
      self->params[self->len - 1u].value.long_rep = va_arg(list, long);
      break;
    }
    case PARAM_FLOAT: {
      self->params[self->len - 1u].value.float_rep = va_arg(list, double);
      break;
    }
    case PARAM_DOUBLE: {
      self->params[self->len - 1u].value.double_rep = va_arg(list, double);
      break;
    }
    case PARAM_CHAR: {
      self->params[self->len - 1u].value.char_rep = va_arg(list, int);
      break;
    }
    case PARAM_UNSIGNED: {
      self->params[self->len - 1u].value.unsigned_rep = va_arg(list, unsigned);
      break;
    }
    case PARAM_UNSIGNED_SHORT: {
      self->params[self->len - 1u].value.unsigned_short_rep =
          va_arg(list, unsigned);
      break;
    }
    case PARAM_UNSIGNED_LONG: {
      self->params[self->len - 1u].value.unsigned_long_rep =
          va_arg(list, unsigned long);
      break;
    }
    case PARAM_UNSIGNED_CHAR: {
      self->params[self->len - 1u].value.unsigned_char_rep =
          va_arg(list, unsigned);
      break;
    }
    case PARAM_PTR: {
      self->params[self->len - 1u].value.pointer_rep = va_arg(list, void *);
      break;
    }
    }
  }
  return self;
}

struct ImParams *ImParams_Push(register struct ImParams *const self,
                               size_t const len, ...) {
  auto va_list list = {0};
  register struct ImParams *ret = NULL;

  va_start(list, len);
  ret = ImParams_VPush(self, len, list);
  va_end(list);
  return ret;
}
