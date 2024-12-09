#ifndef HTMLBUTTON_H_
#define HTMLBUTTON_H_

#include "imlib/imclass.h"

/* 
 * Concrete products provide various implementations of the
 * product interface.
 */

/*
class HTMLButton implements Button is
    method render(a, b) is
        // Return an HTML representation of a button.
    method onClick(f) is
        // Bind a web browser click event.
*/

struct HTMLButton;

extern struct ImClass *const HTMLButton;

#endif /* !HTMLBUTTON_H_ */
