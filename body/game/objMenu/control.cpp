#include "priceDraw.cpp"

void ObjMenu::control()
{
    ProtoObj *u = this->unit;
    if (u &&
        (!u->cell ||
         u->hp <= 0 ||
         u->inSave))
    {
        this->potencialUnit = nullptr;
        this->unit = nullptr;
    }

    if (this->needUpdate)
    {
        this->needUpdate = false;
        this->unit = this->potencialUnit;
        this->units.clear();
        this->potencialUnits.forEach([this](ProtoObj *unit)
                                     { this->units.push(unit); });
    }
    // this->alpha -= 5;
    // this->alpha = this->alpha > 100 ? this->alpha : 255;
};