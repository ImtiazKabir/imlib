#ifndef IMSTR_H_
#define IMSTR_H_

#include <stdarg.h>

#include "imclass.h"
#include "imstdinc.h"

#include "imerrno.h"

#define E4C_NOKEYWORDS
#include "e4c.h"

enum ImStrErr { IMSTR_OK = IM_OK, IMSTR_INDEX_OUT_OF_BOUND };

E4C_DECLARE_EXCEPTION(IndexOutOfBoundException);

struct ImStr;

extern struct ImClass const *ImStr;

PUBLIC char const *ImStr_View(struct ImStr const *self);

PUBLIC void ImStr_Append(struct ImStr *self, char const *cstr);

PUBLIC void ImStr_AppendChar(struct ImStr *self, char c);

PUBLIC void ImStr_AppendInt(struct ImStr *self, int i);

PUBLIC void ImStr_AppendReal(struct ImStr *self, double d);

PUBLIC void ImStr_VAppendFmt(struct ImStr *self, char const *fmt, va_list args);

PUBLIC void ImStr_AppendFmt(struct ImStr *self, char const *fmt, ...);

PUBLIC int ImStr_InsertAt(struct ImStr *self, size_t index, const char *cstr);

PUBLIC int ImStr_Delete(struct ImStr *self, size_t start, size_t end);

PUBLIC int ImStr_SetCharAt(struct ImStr *self, size_t index, char c);

PUBLIC size_t ImStr_Length(struct ImStr *self);

#endif /* !IMSTR_H_ */
