# Factory Design Pattern in imlib
`main.c` instantiate an abstract class `Dialog` with one of two concrete implementations (`WebDialog` or `WinDialog`). `Dialog::Render` then calls the appropriate method to create an appropriate implementation of the `Button` interface ie. `WebDialog` creates `HTMLButton` and `WinDialog` creates `WinButton`. Then the button's render is called.

## Reference:
- https://refactoring.guru/design-patterns/factory-method
