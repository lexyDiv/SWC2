#include "get_G.cpp"

ProtoObj *hzCell = nullptr;

void GameField::getPotentialWay(ProtoObj *unit)
{
    unit->potentialWay.clear();
    unit->isNeedReturnGetPotentialWay = false;
    ProtoObj *finishCell = unit->targetCell;
    ProtoObj *startCell = unit->cell;

    hzCell = unit->targetCell;

    if (
        startCell &&
        finishCell &&
        unit->hp > 0)
    {
        this->createCount += 0.0000001;
        startCell->createCountData = this->createCount;
        this->openArr.clear();
        this->openArr.push(startCell);
        this->quickArr.clear();

        int iter = 0;

        while (true)
        {
            iter++;

            MinData md;

            md = this->openArr.getMinData([](ProtoObj *cell)
                                          { return cell->F; });

            this->min_F_cell = md.cell;

            for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
            {
                ProtoObj *pc = this->min_F_cell->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc, finishCell);
                if (unit->isPotentialWayComplite)
                {
                    break;
                }
            }

            this->openArr.splice(md.index, 1);

            if (unit->isPotentialWayComplite)
            {
                break;
            }
        }
    }
};