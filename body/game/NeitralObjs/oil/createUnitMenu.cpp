#include "create.cpp"

void Oil::createUnitMenu()
{
    this->unitMenu = new UnitMenu;
    this->titleName = "Oil";
    this->unitMenu->titleMenuX = 445;
    this->unitMenu->titleMenuY = 290;
    this->unitMenu->getTitleName = [](ProtoObj *unit)
    {
        return unit->titleName;
    };
    this->unitMenu->getTitl_3_line = [this](ProtoObj *unit)
    {
        return "Oil: " + to_string(this->oil);
    };

};