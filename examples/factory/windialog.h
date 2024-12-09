#ifndef WINDIALOG_H_
#define WINDIALOG_H_

#include "imlib/imclass.h"

/* 
 * Concrete creators override the factory method to change the
 * resulting product's type.
 */


/*
class WindowsDialog extends Dialog is
    method createButton():Button is
        return new WindowsButton()
*/

struct WinDialog;

extern struct ImClass *const WinDialog;

#endif /* !WINDIALOG_H_ */
