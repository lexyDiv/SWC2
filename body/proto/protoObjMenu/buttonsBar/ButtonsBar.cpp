#include "ButtonsBar.h"

ButtonsBar::ButtonsBar()
{
}

ButtonsBar::~ButtonsBar()
{
    this->buttonsArray.forEach([](Array<Button *> line)
                               { line.forEach([](Button *button)
                                              {
            delete button;
            button = nullptr; }); });
}
