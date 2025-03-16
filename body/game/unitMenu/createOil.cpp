#include "createShaht.cpp"

void UnitMenu::createOil()
{
    this->getTitleName = [](ProtoObj *unit)
    {
        return "Oil";
    };

    for (int i = 0; i < 5; i++)
    {
        Lambda lambda;
        this->infoLines.push(lambda);
    }

    this->infoLines.getItem3(2).fn = [](ProtoObj *unit)
    {
        return "Oil: " + to_string(unit->oil);
    };

    this->titleMenuXY = [](ProtoObj *unit)
    {
        Point point = {x : 445, y : 290};
        return point;
    };

    /////////////////////////////// buttons data

    this->isButtons = true;

    Array<Array<ButtonData *>> slice;
    for (int ver = 0; ver < 4; ver++)
    {
        Array<ButtonData *> line;
        for (int hor = 0; hor < 5; hor++)
        {
            ButtonData *buttonData = buttonDataHub.voidButtonData;
            line.push(buttonData);
        };
        slice.push(line);
    };
    this->buttonsData.push(slice);

    this->buttonsData.getItem3(0).getItem3(3).changeEl(buttonDataHub.outButtonData, 4);
};