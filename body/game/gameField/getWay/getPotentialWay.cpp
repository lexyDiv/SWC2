#include "get_G.cpp"

ProtoObj *hzCell = nullptr;

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
        this->min_F_cell = startCell;

        int iter = 0;
       // auto start_time = std::chrono::steady_clock::now();

        while (true)
        {
            iter++;
   
            MinData md;

            for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
            {
                ProtoObj *pc = this->min_F_cell->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc, finishCell);
            }

                int index = this->openArr.length - 1;
                md.cell = this->openArr.getItem(this->openArr.length - 1);
                md.index = index;
                for (int i = index; i >= 0; i--)
                {
                    ProtoObj *cell = this->openArr.getItem(i);
                    if (md.cell->F >= cell->F)
                    {
                        md.cell = cell;
                        md.index = i;
                        if (cell->F < this->min_F_cell->F) {
                            break;
                        }
                    }
                }
                this->openArr.splice(md.index, 1);
            
            this->min_F_cell = md.cell;
            this->min_F_cell->explored = this->createCount;

            ///////////////////////////////////////////////////////

            if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell) ||
                unit->isNeedReturnGetPotentialWay)
            {
                if (!unit->isNeedReturnGetPotentialWay)
                {
                    this->potentialWayCreate(unit, this->min_F_cell);
                }
                break;
            }

            if (!this->quickArr.length && !this->openArr.length)
            {
                unit->isPotentialWayComplite = true;
                break;
            }
        }
        // auto end_time = std::chrono::steady_clock::now();
        // auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        // console.log(to_string(res.count()));
        // console.log(to_string(iter));
    }
};
