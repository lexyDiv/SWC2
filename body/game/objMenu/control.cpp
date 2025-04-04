#include "priceDraw.cpp"

void ObjMenu::control()
{
    if (this->needUpdate)
    {
        this->needUpdate = false;
        this->unit = this->potencialUnit;
        this->units.clear();
        this->potencialUnits.forEach([this](ProtoObj *unit)
                                     { this->units.push(unit); });
    }
    this->alpha -= 5;
    this->alpha = this->alpha > 100 ? this->alpha : 255;
};