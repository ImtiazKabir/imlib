#include "dialog.h"

#include "button.h"
#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/impanic.h"

static void __Constructor__(void *_self, struct ImParams *args) {
  struct Dialog *self = _self;
  (void)args;
  self->create_button = Dialog_CreateButton;
}

static void __Destructor__(void *self) {
  (void)self;
}

struct Button *Dialog_CreateButton(struct Dialog *self) {
  (void)self;
  impanic("Class does not concretely implement Dialog_CreateButton\n");
  return NULL;
}

void Dialog_Render(struct Dialog *self) {
  struct Button *button = self->create_button(self);
  Button_OnClick(button);
  Button_Render(button);
  imdel(button);
}

CLASS(Dialog) {
  _Dialog.size = sizeof(struct Dialog);
  _Dialog.ctor = __Constructor__;
  _Dialog.dtor = __Destructor__;
}

