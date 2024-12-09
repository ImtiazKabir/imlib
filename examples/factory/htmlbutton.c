#include "htmlbutton.h"
#include "imlib/imparam.h"
#include "imlib/imclass.h"
#include "imlib/imclass_prot.h"
#include "imlib/imstdinc.h"
#include "imlib/impanic.h"
#include "imlib/immem.h"
#include "imlib/imlog.h"

#include "button.h"

struct HTMLButton {
  char unused;
};

static void __Constructor__(void *self, struct ImParams *args) {
  (void)self, (void)args;
}

static void __Destructor__(void *self) {
  (void)self;
}

static void __Render__(void *self) {
  (void)self;
  imlog(LOG_INFO, "HTMLButton::Render");
}

static void __OnClick__(void *self) {
  (void)self;
  imlog(LOG_INFO, "HTMLButton::OnClick");
}

static void __InterfaceImplementation__(void *interface) {
  if (imisof(interface, Button) != IM_FALSE) {
    struct Button *button_interface = interface;
    button_interface->render = __Render__;
    button_interface->on_click = __OnClick__;
  } else {
    impanic("HTMLButton does not implement %s\n", imtype(interface));
  }
}

CLASS(HTMLButton) {
  _HTMLButton.size = sizeof(struct HTMLButton);
  _HTMLButton.ctor = __Constructor__;
  _HTMLButton.dtor = __Destructor__;
  _HTMLButton.implof = __InterfaceImplementation__;
}

