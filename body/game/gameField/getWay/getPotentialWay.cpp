#include "get_G.cpp"

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
        startCell->createCountData = this->createCount;
        this->openArr.clear();
        this->openArr.push(startCell);

        // this->exploreNewCellAndAddToOpenArr(unit, nullptr, startCell, finishCell);

        while (true)
        {

            ProtoObj *max_F_cell = this->openArr.getMin([](ProtoObj *cell)
                                                        { return cell->F; });
            max_F_cell->aroundCells.forEach([this, unit, startCell, finishCell, max_F_cell](ProtoObj *pc)
                                            { this->exploreNewCellAndAddToOpenArr(unit, max_F_cell, pc, finishCell); });

            this->openArr.filterSelf([max_F_cell](ProtoObj *cell)
                                     { return cell == max_F_cell; });

            unit->isPotentialWayComplite = true;
            break;
        }
        // console.log("scan way for unit");
    }
};