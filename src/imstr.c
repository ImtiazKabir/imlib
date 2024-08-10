#include "imlib/imstr.h"

#include <memory.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "imlib/immem.h"

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"

#include "imlib/imerrno.h"
#include "imlib/impanic.h"
#include "imlib/imparam.h"
#include "imlib/imstdinc.h"

#define IMSTR_INITIAL_CAPACITY 16u

struct ImStr {
  char *str;
  size_t length;
  size_t capacity;
};

PRIVATE void __init__(struct ImStr *self) {
  self->capacity = IMSTR_INITIAL_CAPACITY;
  self->length = 0u;
  self->str = imalloct("String", self->capacity * sizeof(char));
}

PRIVATE void __deinit__(struct ImStr *self) {
  imfree(self->str);
  self->str = NULL;
  self->length = 0u;
  self->capacity = IMSTR_INITIAL_CAPACITY;
}

PRIVATE void __constructor__(register void *const self,
                             register struct ImParams *args) {
  if (ImParams_Match(args, 0u) == IM_FALSE) {
    impanic("%s\n", "ImStr constructor does not take any parameter");
  }

  __init__(self);
}

PRIVATE void __destructor__(register void *const self) { __deinit__(self); }

PRIVATE void __clone__(register void *const _self,
                       register void const *const _from) {
  register struct ImStr *const self = _self;
  register struct ImStr const *const from = _from;

  self->capacity = from->capacity;
  self->str = imalloct("String", self->capacity * sizeof(char));
  (void)strcpy(self->str, from->str);
  self->length = from->length;
}

PRIVATE void __assign__(register void *const _self,
                        register void const *const _from) {
  register struct ImStr *const self = _self;
  register struct ImStr const *const from = _from;

  imfree(self->str);
  self->capacity = from->capacity;
  self->str = imalloct("String", self->capacity * sizeof(char));
  (void)strcpy(self->str, from->str);
  self->length = from->length;
}

PRIVATE int __compare__(register void const *const _a,
                        register void const *const _b) {
  register struct ImStr const *const a = _a;
  register struct ImStr const *const b = _b;
  return strcmp(a->str, b->str);
}

PRIVATE char *__dupstr__(register char const *const src) {
  return strcpy(imalloct("String", (strlen(src) + 1u) * sizeof(char)), src);
}

PRIVATE char *__tostr__(register void const *const _self) {
  register struct ImStr const *const self = _self;
  return __dupstr__(self->str);
}

PRIVATE void __ensure_capacity__(register struct ImStr *const self,
                                 register size_t const minimum_capacity) {
  if (minimum_capacity < self->capacity) {
    return;
  }
  while (self->capacity < minimum_capacity) {
    self->capacity <<= 1u;
  }
  self->str = imrealloc(self->str, self->capacity * sizeof(char));
}

PUBLIC char const *ImStr_View(register struct ImStr const *const self) {
  return self->str;
}

PUBLIC void ImStr_Append(register struct ImStr *const self,
                         register char const *const cstr) {
  register size_t len = strlen(cstr);
  __ensure_capacity__(self, self->length + len + 1u);
  (void)strcpy(self->str + self->length, cstr);
  self->length += len;
}

PUBLIC void ImStr_AppendChar(register struct ImStr *const self,
                             register char const c) {
  auto char buffer[2u] = {0};
  buffer[0u] = c;
  ImStr_Append(self, buffer);
}

PUBLIC void ImStr_AppendInt(register struct ImStr *const self,
                            register int const i) {
  auto char buffer[12u] = {0};
  (void)sprintf(buffer, "%d", i);
  ImStr_Append(self, buffer);
}

PUBLIC void ImStr_AppendReal(register struct ImStr *const self,
                             register double const d) {
  auto char buffer[32u] = {0};
  (void)sprintf(buffer, "%f", d);
  ImStr_Append(self, buffer);
}

PUBLIC void ImStr_VAppendFmt(register struct ImStr *const self,
                             register char const *const fmt,
                             register va_list args) {
  enum { MX_BUF_SIZE = 1024 };
  auto char tmp_buf[MX_BUF_SIZE] = {0};

  (void)vsprintf(tmp_buf, fmt, args);
  ImStr_Append(self, tmp_buf);
}

PUBLIC void ImStr_AppendFmt(register struct ImStr *const self,
                            char const *const fmt, ...) {
  auto va_list args = {0};
  va_start(args, fmt);
  ImStr_VAppendFmt(self, fmt, args);
  va_end(args);
}

PUBLIC int ImStr_InsertAt(register struct ImStr *const self,
                          register size_t const index,
                          register const char *const cstr) {
  register size_t const len = strlen(cstr);

  if (index > self->length) {
    imerr(IMSTR_INDEX_OUT_OF_BOUND, "Index out of bound");
    return imerrno();
  }

  __ensure_capacity__(self, self->length + len + 1u);
  memmove(self->str + index + len, self->str + index, self->length - index + 1);
  memcpy(self->str + index, cstr, len);
  self->length += len;

  return IM_OK;
}

PUBLIC int ImStr_Delete(register struct ImStr *const self,
                        register size_t const start,
                        register size_t const end) {
  if ((start > self->length) || (end > self->length)) {
    imerr(IMSTR_INDEX_OUT_OF_BOUND, "Index out of bound");
    return imerrno();
  }

  if (start > end) {
    imerr(IMERR_ILLEGAL_ARG, "start index > end index");
    return imerrno();
  }

  memmove(self->str + start, self->str + end, self->length - end + 1u);
  return IM_OK;
}

PUBLIC int ImStr_SetCharAt(register struct ImStr *const self,
                           register size_t index, register char const c) {
  /* TODO do something about writing '\0' maybe? */
  if (index >= self->length) {
    imerr(IMSTR_INDEX_OUT_OF_BOUND, "Index out of bound");
    return imerrno();
  }

  self->str[index] = c;
  return IM_OK;
}

PUBLIC size_t ImStr_Length(register struct ImStr *const self) {
  return self->length;
}

CLASS(ImStr) {
  _ImStr.size = sizeof(struct ImStr);
  _ImStr.ctor = __constructor__;
  _ImStr.dtor = __destructor__;
  _ImStr.clone = __clone__;
  _ImStr.assign = __assign__;
  _ImStr.compare = __compare__;
  _ImStr.tostr = __tostr__;
}
