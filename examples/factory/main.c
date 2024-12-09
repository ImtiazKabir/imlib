#include "dialog.h"
#include "webdialog.h"
#include "windialog.h"
#include "imlib/impanic.h"

int main(int argc, char **argv) {
  struct Dialog *dialog;

  (void)argc;
  trace_target = argv[0];

  dialog = imnew(WinDialog, 0);
  Dialog_Render(dialog);
  imdel(dialog);

  return 0;
}

