#ifndef IMLIB_I_MAP_H_
#define IMLIB_I_MAP_H_

#include "../imclass.h"
#include "../imerror.h"
#include "../imoption.h"
#include "../imresult.h"
#include "../imstdinc.h"

struct ImIMap {
  size_t (*len)(void *map);
  struct ImOptPtr (*get)(void *map, void *key);
  void (*set_key_policy)(void *map, enum DataPolicy policy);
  void (*set_val_policy)(void *map, enum DataPolicy policy);
  void (*add_or_replace)(void *map, void *key, void *value);
  void (*remove_if_exists)(void *map, void *key);
};

extern struct ImClass *const ImIMap;

PUBLIC size_t ImIMap_Len(void *map);
PUBLIC struct ImOptPtr ImIMap_Get(void *map, void *key);
PUBLIC void ImIMap_SetKeyPolicy(void *map, enum DataPolicy policy);
PUBLIC void ImIMap_SetValPolicy(void *map, enum DataPolicy policy);
PUBLIC void ImIMap_AddOrReplace(void *map, void *key, void *value);
PUBLIC void ImIMap_RemoveIfExists(void *map, void *key);

#endif /* IMLIB_I_MAP_H_ */