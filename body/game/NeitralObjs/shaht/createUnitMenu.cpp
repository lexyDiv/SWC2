#include "create.cpp"

void Shaht::createUnitMenu()
{
    this->unitMenu = new UnitMenu;
    this->titleName = "Gold mine";
    this->unitMenu->titleMenuX = 200;
    this->unitMenu->titleMenuY = 290;
    this->unitMenu->isButtons = true;
    this->unitMenu->getTitleName = [](ProtoObj *unit)
    {
        return unit->titleName;
    };
    this->unitMenu->create(this);
    this->unitMenu->infoLines.getItem3(2).fn = [](ProtoObj *unit)
    {
        return "Gold: " + to_string(unit->gold);
    };
};