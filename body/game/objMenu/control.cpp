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
        this->unit->focus = false;
        this->unit = nullptr;
    }

    // if (u) {
    //    // console.log(u->profession);
    //    u->takeDamage(1);
    // }

    if (this->needUpdate)
    {
        this->needUpdate = false;
        if (this->unit)
        {
            this->unit->focus = false;
        }
        this->unit = this->potencialUnit;
        if (this->unit)
        {
            this->unit->focus = true;
        }
        this->units.clear();
        this->potencialUnits.forEach([this](ProtoObj *unit)
                                     { this->units.push(unit); });
    }
    // this->alpha -= 5;
    // this->alpha = this->alpha > 100 ? this->alpha : 255;
    // if (this->unit) {
    //     ProtoObj *u = this->unit;
    //     console.log(to_string(u->isActive));
    // }
};