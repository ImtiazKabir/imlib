#ifndef WEBDIALOG_H_
#define WEBDIALOG_H_

#include "imlib/imclass.h"

/* 
 * Concrete creators override the factory method to change the
 * resulting product's type.
 */

/*
class WebDialog extends Dialog is
    method createButton():Button is
        return new HTMLButton()
*/

struct WebDialog;

extern struct ImClass *const WebDialog;

#endif /* !WEBDIALOG_H_ */
