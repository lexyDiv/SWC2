#include "control.cpp"

void ObjMenu::draw()
{
    if (this->unit)
    {
        this->titleUnit.draw(this->unit, this);
        if (this->unit->unitMenu->isButtons)
        {
            this->buttonsBar.draw();
        }
    }
};