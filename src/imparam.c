#include "imlib/imparam.h"
#include "imlib/imstdinc.h"

#include "imlib/imparam.h"
#include <stdarg.h>

PUBLIC struct ImParams *ImParams_VPush(register struct ImParams *const self,
                                       register size_t const len,
                                       register va_list list) {
  register size_t i = 0u;
  if (self == NULL) {
    return NULL;
  }

  for (i = 0u; i < len; i += 1u) {
    register enum ParamType type = 0;
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

PUBLIC struct ImParams *ImParams_Push(register struct ImParams *const self,
                                      size_t const len, ...) {
  auto va_list list = {0};
  register struct ImParams *ret = NULL;

  va_start(list, len);
  ret = ImParams_VPush(self, len, list);
  va_end(list);
  return ret;
}

PUBLIC ImBool ImParams_Match(register struct ImParams const *const self,
                             size_t const len, ...) {
  auto va_list list = {0};

  if (self->len != len) {
    return IM_FALSE;
  }

  va_start(list, len);

  FOR(size_t i, i = 0u; i < len; i += 1u, {
    register enum ParamType const type = va_arg(list, unsigned);
    if (self->params[i].type != type) {
      va_end(list);
      return IM_FALSE;
    }
  })

  va_end(list);
  return IM_TRUE;
}

PUBLIC void ImParams_Extract(struct ImParams const *const self, ...) {
  auto va_list list = {0};
  va_start(list, self);
  FOR(size_t i, i = 0u; i < self->len; i += 1u, {
    register void *const ptr = va_arg(list, void *);
    register enum ParamType type = self->params[i].type;
    switch (type) {
    case PARAM_INT: {
      *(int *)ptr = self->params[i].value.int_rep;
      break;
    }
    case PARAM_SHORT: {
      *(short *)ptr = self->params[i].value.short_rep;
      break;
    }
    case PARAM_LONG: {
      *(long *)ptr = self->params[i].value.long_rep;
      break;
    }
    case PARAM_FLOAT: {
      *(float *)ptr = self->params[i].value.float_rep;
      break;
    }
    case PARAM_DOUBLE: {
      *(double *)ptr = self->params[i].value.double_rep;
      break;
    }
    case PARAM_CHAR: {
      *(char *)ptr = self->params[i].value.char_rep;
      break;
    }
    case PARAM_UNSIGNED: {
      *(unsigned *)ptr = self->params[i].value.unsigned_rep;
      break;
    }
    case PARAM_UNSIGNED_SHORT: {
      *(unsigned short *)ptr = self->params[i].value.unsigned_short_rep;
      break;
    }
    case PARAM_UNSIGNED_LONG: {
      *(unsigned long *)ptr = self->params[i].value.unsigned_long_rep;
      break;
    }
    case PARAM_UNSIGNED_CHAR: {
      *(unsigned char *)ptr = self->params[i].value.unsigned_char_rep;
      break;
    }
    case PARAM_PTR: {
      *(void **)ptr = self->params[i].value.pointer_rep;
      break;
    }
    }
  })
  va_end(list);
}
