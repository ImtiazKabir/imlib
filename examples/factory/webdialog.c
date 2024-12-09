#include "webdialog.h"
#include "dialog.h"

#include "htmlbutton.h"
#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"

struct WebDialog {
  struct Dialog base;
};

static struct Button *__CreateButton__(struct Dialog *self) {
  (void)self;
  return imnew(HTMLButton, 0u);
}

static void __Constructor__(void *self, struct ImParams *args) {
  struct Dialog *super = self;
  (void)args;
  super->create_button = __CreateButton__;
}

static void __Destructor__(void *self) {
  (void)self;
}

static void __super_params__(register struct ImParams *sup_args,
                                    register struct ImParams *self_args) {
  (void)sup_args, (void)self_args;
}


CLASS(WebDialog) {
  _WebDialog.super_class = Dialog;
  _WebDialog.size = sizeof(struct WebDialog);
  _WebDialog.ctor = __Constructor__;
  _WebDialog.dtor = __Destructor__;
  _WebDialog.super_params = __super_params__;
}

