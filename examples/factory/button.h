#ifndef BUTTON_H_
#define BUTTON_H_

#include "imlib/imclass.h"

/*
  * The product interface declares the operations that all 
  * concrete products must implement.
*/

/*
interface Button is
    method render()
    method onClick(f)
*/

struct Button {
  void (*render)(void *button);
  void (*on_click)(void *button); /* TODO: take a dialog as input */
};

extern struct ImClass *const Button;

void Button_Render(void *button);
void Button_OnClick(void *buttin); /* TODO: take a dialog as input */

#endif /* !BUTTON_H_ */
