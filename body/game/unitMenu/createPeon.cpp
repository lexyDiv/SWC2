#include "unitMenuPack.h"

void UnitMenu::createPeon()
{

    this->speed = 1;

    this->getTitleName = [](ProtoObj *unit)
    {
        return "Peon";
    };

    for (int i = 0; i < 5; i++)
    {
        Lambda lambda;
        switch (i)
        {

        case 0:
            lambda.fn = [](ProtoObj *unit)
            {
                return "Level:  " + to_string(unit->getLevel());
            };
            break;

        case 1:
            lambda.fn = [](ProtoObj *unit)
            {
                return "Attack: " + to_string(unit->attack);
            };
            break;

        case 2:
            lambda.fn = [](ProtoObj *unit)
            {
                return "Armor:  " + to_string(unit->armor);
            };
            break;

        case 3:
            lambda.fn = [this](ProtoObj *unit)
            {
                return "Speed:  " + to_string((int)this->speed);
            };
            break;

        case 4:
            lambda.fn = [](ProtoObj *unit)
            {
                return "Sight:  " + to_string(unit->sight);
            };
            break;

        default:
            break;
        }
        this->infoLines.push(lambda);
    }

    this->titleMenuXY = [](ProtoObj *unit)
    {
        Point point = {x : 53, y : 3};
        return point;
    };

    this->getIsHp = [](ProtoObj *unit)
    {
        return true;
    };

    this->targetObjControl = [](ProtoObj *unit)
    {
        unit->targetObj.unit = nullptr;
    };

    this->targetObjControlWood = [](ProtoObj *unit)
    {
        ProtoObj *cell = unit->potentialWay.getItem(0);
        ProtoObj *gu = cell->groundUnit;
        if (!gu || gu->name != "tree" || unit->wood)
        {
            unit->targetObj.unit = nullptr;
            unit->profession = "";
        }
        else
        {
            unit->targetObj.unit = gu;
            unit->targetObj.bornCount = gu->bornCount;
        }
    };

    this->targetObjControlBuilding = [](ProtoObj *unit)
    {
        ProtoObj *cell = unit->potentialWay.getItem(0);
        ProtoObj *gu = cell->groundUnit;
        if (!gu || gu != unit->targetObj.unit ||
            gu->type == "life" ||
            gu->hp <= 0 ||
            unit->targetObj.bornCount != gu->bornCount ||
            (gu->fraction && gu->fraction != unit->fraction) ||
            (unit->gold > 0 && gu->name == "shaht"))
        {
            unit->targetObj.unit = nullptr;
            unit->profession = "";
        }
    };

    this->targetObjControlWoodComp = [](ProtoObj *unit)
    {
        ProtoObj *cell = unit->potentialWay.getItem(0);
        ProtoObj *gu = cell->groundUnit;

        if (!unit->iNeedFreeWay &&
            (!gu || gu->name != "tree"))
        {
            console.log("i need free way to tree");
            unit->iNeedFreeWay = true;
            unit->getHandTarget(unit->preTargetCell);
            return;
        }

        if (!gu ||
            gu->name != "tree" || unit->wood)
        {
            unit->targetObj.unit = nullptr;
            unit->profession = "";
            console.log("i dont see valide trees !!!");
            console.log("targetObjControlWoodComp");
        }
    };

    this->targetObjControlBuildingComp = [](ProtoObj *unit)
    {
        ProtoObj *cell = unit->potentialWay.getItem(0);
        ProtoObj *gu = cell->groundUnit;
        if (!gu ||
            gu->type == "life" ||
            unit->targetObj.bornCount != gu->bornCount ||
            gu->hp <= 0 ||
            (unit->gold > 0 && gu->name == "shaht"))
        {
            unit->targetObj.unit = nullptr;
            unit->profession = "";
            return;
        }
        if (!unit->iNeedFreeWay &&
            (!gu || gu != unit->targetObj.unit))
        {
            console.log("i need free way to building");
            unit->iNeedFreeWay = true;
            unit->getHandTarget(unit->preTargetCell);
        }
    };

    //////////////////////////// conirs
    //     ProtoObj *left = nullptr;
    // ProtoObj *right = nullptr;
    // ProtoObj *top = nullptr;
    // ProtoObj *bottom = nullptr;
    // ProtoObj *top_left = nullptr;
    // ProtoObj *top_right = nullptr;
    // ProtoObj *bottom_left = nullptr;
    // ProtoObj *bottom_right = nullptr;

    // double speed = 0;
    // double cellSize = 48;
    // double degDis = 67.882251;
    // double wayTaktCountForward = 0;
    // double wayTaktCountDeg = 0;

    conorLeft = degToRad(180);
    leftDeltaX = cos(conorLeft) * this->speed;
    leftDeltaY = sin(conorLeft) * this->speed;
    conorRight = degToRad(0);
    rightDeltaX = cos(conorRight) * this->speed;
    rightDeltaY = sin(conorRight) * this->speed;
    conorTop = degToRad(270);
    topDeltaX = cos(conorTop) * this->speed;
    topDeltaY = sin(conorTop) * this->speed;
    conorBottom = degToRad(90);
    bottomDeltaX = cos(conorBottom) * this->speed;
    bottomDeltaY = sin(conorBottom) * this->speed;
    conorTop_left = degToRad(225);
    top_leftDeltaX = cos(conorTop_left) * this->speed;
    top_leftDeltaY = sin(conorTop_left) * this->speed;
    conorTop_right = degToRad(315);
    top_rightDeltaX = cos(conorTop_right) * this->speed;
    top_rightDeltaY = sin(conorTop_right) * this->speed;
    conorBottom_left = degToRad(135);
    bottom_leftDeltaX = cos(conorBottom_left) * this->speed;
    bottom_leftDeltaY = sin(conorBottom_left) * this->speed;
    conorBottom_right = degToRad(45);
    bottom_rightDeltaX = cos(conorBottom_right) * this->speed;
    bottom_rightDeltaY = sin(conorBottom_right) * this->speed;
};
