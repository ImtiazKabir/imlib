#include "imlib/imio.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "imlib/immem.h"
#include "imlib/imlog.h"

PRIVATE char *__dupstr__(register char const *const src) {
  return strcpy(imalloct("String", (strlen(src) + 1u) * sizeof(char)), src);
}

PUBLIC int imputobj(register void const *const self, register FILE *const fp) {
  register char *const str = imtostr(self);
  register int const ret = fputs(str, fp);
  (void)imfree(str);
  return ret;
}

PUBLIC int imvfprintf(register FILE *const fp, register char const *const fmt,
                      register va_list ap) {
  register char *needle_beg = NULL;
  register size_t needle_index = 0u;
  register void *obj_ptr = NULL;
  register char *copy = NULL;
  register int ret = 0;

  if (fmt == NULL) {
    return 0;
  }

  needle_beg = strstr(fmt, "%obj");
  if (needle_beg == NULL) {
    return vfprintf(fp, fmt, ap);
  }

  needle_index = needle_beg - fmt;

  copy = __dupstr__(fmt);
  copy[needle_index] = '\0';
  ret += vfprintf(fp, copy, ap);
  (void)imfree(copy);

  obj_ptr = va_arg(ap, void *);
  ret += imputobj(obj_ptr, fp);
  ret += imvfprintf(fp, needle_beg + 4u, ap);
  return ret;
}

PUBLIC int imvprintf(register char const *const fmt, register va_list ap) {
  return imvfprintf(stdout, fmt, ap);
}

PUBLIC int imfprintf(register FILE *const fp, char const *const fmt, ...) {
  auto va_list ap;
  register int ret = 0;

  va_start(ap, fmt);
  ret = imvfprintf(fp, fmt, ap);
  va_end(ap);
  return ret;
}

PUBLIC int imprintf(char const *const fmt, ...) {
  auto va_list ap;
  register int ret = 0;

  va_start(ap, fmt);
  ret = imvprintf(fmt, ap);
  va_end(ap);
  return ret;
}


PUBLIC int imvsprintf(register char *const str, register char const *const fmt, register va_list ap) {
  register char *needle_beg = NULL;
  register size_t needle_index = 0u;
  register void *obj_ptr = NULL;
  register char *copy = NULL;
  register char *obj_str = NULL;
  register int ret = 0;

  if (fmt == NULL) {
    return 0;
  }

  needle_beg = strstr(fmt, "%obj");
  if (needle_beg == NULL) {
    return vsprintf(str, fmt, ap);
  }

  needle_index = needle_beg - fmt;

  copy = __dupstr__(fmt);
  copy[needle_index] = '\0';
  ret += vsprintf(str, copy, ap);
  (void)imfree(copy);

  obj_ptr = va_arg(ap, void *);
  obj_str = imtostr(obj_ptr);
  (void)strcpy(str + ret, obj_str);
  ret += strlen(obj_str);
  (void)imfree(obj_str);

  ret += imvsprintf(str + ret, needle_beg + 4u, ap);
  return ret;
}

PUBLIC int imsprintf(register char *const str, char const *const fmt, ...) {
  auto va_list ap;
  register int ret = 0;

  va_start(ap, fmt);
  ret = imvsprintf(str, fmt, ap);
  va_end(ap);
  return ret;
}
