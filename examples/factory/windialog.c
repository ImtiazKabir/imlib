#include "windialog.h"
#include "dialog.h"

#include "winbutton.h"
#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"

struct WinDialog {
  struct Dialog base;
};

static struct Button *__CreateButton__(struct Dialog *self) {
  (void)self;
  return imnew(WinButton, 0u);
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

CLASS(WinDialog) {
  _WinDialog.super_class = Dialog;
  _WinDialog.size = sizeof(struct WinDialog);
  _WinDialog.ctor = __Constructor__;
  _WinDialog.dtor = __Destructor__;
  _WinDialog.super_params = __super_params__;
}

