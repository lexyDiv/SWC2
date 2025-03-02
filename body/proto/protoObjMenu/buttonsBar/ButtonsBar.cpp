#include "ButtonsBar.h"

ButtonsBar::ButtonsBar()
{
}

ButtonsBar::~ButtonsBar()
{
    this->buttonsArray.forEach([](Button* button){
        delete button;
        button = nullptr;
    });
}
