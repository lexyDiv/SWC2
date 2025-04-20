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
        this->priceDraw();
    }
    else if (this->potencialUnits.length)
    {
        this->isWarriors = true;
        for (int i = 0; i < this->potencialUnits.length; i++)
        {
            ProtoObj *unit = this->potencialUnits.getItem(i);
            if (!unit->cell)
            {
                this->potencialUnits.splice(i, 1);
            }
            else if (!unit->isWarrior)
            {
                this->isWarriors = false;
                break;
            };
        }
        this->drawGropup();
    }
};