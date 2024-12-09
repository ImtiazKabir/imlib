#ifndef DIALOG_H_
#define DIALOG_H_

#include "imlib/imclass.h"

#include "button.h"

/*
 * The creator class declares the factory method that must
 * return an object of a product class. The creator's subclasses
 * usually provide the implementation of this method.
*/

/*
class Dialog is
    // The creator may also provide some default implementation
    // of the factory method.
    abstract method createButton():Button

    // Note that, despite its name, the creator's primary
    // responsibility isn't creating products. It usually
    // contains some core business logic that relies on product
    // objects returned by the factory method. Subclasses can
    // indirectly change that business logic by overriding the
    // factory method and returning a different type of product
    // from it.
    method render() is
        // Call the factory method to create a product object.
        Button okButton = createButton()
        // Now use the product.
        okButton.onClick(closeDialog)
        okButton.render()
*/

struct Dialog {
  struct Button *(*create_button)(struct Dialog *self);
};

extern struct ImClass *const Dialog;

struct Button *Dialog_CreateButton(struct Dialog *self);
void Dialog_Render(struct Dialog *self);


#endif /* !DIALOG_H_ */
