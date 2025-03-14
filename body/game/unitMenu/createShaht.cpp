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
};