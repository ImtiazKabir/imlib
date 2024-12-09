#ifndef WINBUTTON_H_
#define WINBUTTON_H_

#include "imlib/imclass.h"

/* 
 * Concrete products provide various implementations of the
 * product interface.
 */

/*
class WindowsButton implements Button is
    method render(a, b) is
        // Render a button in Windows style.
    method onClick(f) is
        // Bind a native OS click event.
*/


struct WinButton;

extern struct ImClass *const WinButton;

#endif /* !WINBUTTON_H_ */
