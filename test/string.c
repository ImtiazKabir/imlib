#ifndef __STDC_VERSION__
#define inline /* inline */
#endif
#include <criterion/criterion.h>

#include "imlib/imclass.h"
#include "imlib/imstr.h"

Test(imstr, constructor_with_no_var_args) {
  register struct ImStr *const str = imnew(ImStr, "Hello");
  cr_assert_str_eq("Hello", ImStr_View(str),
                   "Counstructor args not found in inner str");
  imdel(str);
}
