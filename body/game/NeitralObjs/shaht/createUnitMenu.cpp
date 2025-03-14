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

     ////////////////////////////////// out button
     ButtonData *bd = this->unitMenu->buttonsData.getItem(0).getItem(3).getItem(4);
     bd->update = [bd](ProtoObj* unit){
        return bd;
    };
    bd->onClick = [](ProtoObj* unit){
        unit->gf->game->objMenu->defaultData();
    };
    bd->infoString = "Close menu";
    /////////////////////////
};