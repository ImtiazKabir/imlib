#include "button.h"

#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/immem.h"
#include "imlib/imparam.h"

static void __Constructor__(void *self, struct ImParams *args) {
  (void)self, (void)args;
}

static void __Destructor__(void *self) {
  (void)self;
}

void Button_Render(void *button) {
  struct Button *self = imnew(Button, 0u);
  struct ImClass *klass = imclass(button);
  klass->implof(self);
  self->render(button);
  imdel(self);
}

void Button_OnClick(void *button) {
  struct Button *self = imnew(Button, 0u);
  struct ImClass *klass = imclass(button);
  klass->implof(self);
  self->on_click(button);
  imdel(self);
}

CLASS(Button) {
  _Button.size = sizeof(struct Button);
  _Button.ctor = __Constructor__;
  _Button.dtor = __Destructor__;
}
