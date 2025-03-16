#include "default.cpp"

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
};