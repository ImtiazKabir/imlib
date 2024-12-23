#ifndef IMLIB_IMPAIR_H_
#define IMLIB_IMPAIR_H_

#include "imstdinc.h"
#include "imclass.h"

struct ImPair;
extern struct ImClass *const ImPair;

PUBLIC void ImPair_SetKey(struct ImPair *self, void *key);
PUBLIC void ImPair_SetValue(struct ImPair *self, void *value);

PUBLIC void ImPair_SetKeyWithPolicy(struct ImPair *self, void *key, enum DataPolicy policy);
PUBLIC void ImPair_SetValueWithPolicy(struct ImPair *self, void *value, enum DataPolicy policy);

PUBLIC void *ImPair_KeyView(struct ImPair const *self);
PUBLIC void *ImPair_ValueView(struct ImPair const *self);


#endif /* !IMLIB_IMPAIR_H_ */


