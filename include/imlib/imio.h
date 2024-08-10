#ifndef IMIO_H_
#define IMIO_H_

#include <stdarg.h>
#include <stdio.h>

#include "imstdinc.h"

PUBLIC int imputobj(void const *self, FILE *fp);

PUBLIC int imvfprintf(FILE *fp, char const *fmt, va_list ap);
PUBLIC int imvprintf(char const *fmt, va_list ap);
PUBLIC int imfprintf(FILE *fp, char const *fmt, ...);
PUBLIC int imprintf(char const *fmt, ...);

#endif /* !IMIO_H_ */
