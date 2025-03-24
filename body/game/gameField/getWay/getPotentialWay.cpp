#include "../fieldClick.cpp"

void GameField::getPotentialWay(ProtoObj *unit)
{
    unit->potentialWay.clear();
    unit->isNeedReturnGetPotentialWay = false;
    ProtoObj *finishCell = unit->targetCell;
    ProtoObj *startCell = unit->cell;

    if (
        startCell &&
        finishCell &&
        unit->hp > 0)
    {
        this->createCount += 0.0000001;
        this->openArr.clear();

        this->exploreNewCellAndAddToOpenArr(unit, nullptr, startCell);

        while (true)
        {
            unit->isPotentialWayComplite = true;
            break;
        }
        console.log("scan way for unit");
    }
};