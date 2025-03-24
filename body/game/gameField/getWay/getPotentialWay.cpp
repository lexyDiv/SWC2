#include "../fieldClick.cpp"



void GameField::getPotentialWay(ProtoObj *unit)
{
    unit->potentialWay.clear();
    ProtoObj *finishCell = unit->handTargetCell ? unit->handTargetCell : unit->targetCell;
    ProtoObj* startCell = unit->cell;

    if (startCell && finishCell)
    {
        this->createCount += 0.0000001;
        this->openArr.clear();

        this->cellFormat(startCell);

        while (!unit->isPotentialWayComplite)
        {
            
            unit->isPotentialWayComplite = true;
        }
        console.log("scan way for unit");
    }
};