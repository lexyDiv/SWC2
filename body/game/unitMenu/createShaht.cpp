#include "unitMenuPack.h"

void UnitMenu::createShaht()
{
    this->getTitleName = [](ProtoObj *unit)
    {
        return "Gold mine";
    };

    for (int i = 0; i < 5; i++)
    {
        Lambda lambda;
        this->infoLines.push(lambda);
    }

    this->infoLines.getItem3(2).fn = [](ProtoObj *unit)
    {
        return "Gold: " + to_string(unit->gold);
    };

    this->titleMenuXY = [](ProtoObj *unit){
        Point point = {x: 200, y: 290};
        return point;
    };
};