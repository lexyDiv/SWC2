#include "get_G.cpp"

ProtoObj *hzCell = nullptr;

void GameField::getPotentialWay(ProtoObj *unit)
{
     // auto start_time = std::chrono::steady_clock::now();

    unit->potentialWay.clear();
    unit->isNeedReturnGetPotentialWay = false;
    unit->getCurrentTargetCell();

    //   ProtoObj *finishCell = unit->targetCell;
    //    ProtoObj *startCell = unit->cell;
    // hzCell = finishCell;
    if (
        unit->hp > 0)
    {
        this->createCount += 0.0000001;
        unit->cell->createCountData = this->createCount;
        this->openArr.clear();
        this->min_F_cell = unit->cell;

        int iter = 0;

        while (true)
        {
            iter++;

            MinData md;

            // if (!this->min_F_cell) {
            //     unit->isPotentialWayComplite = true;
            //     return;
            // };

            if (unit->isNeedReturnGetPotentialWay)
            {
                return;
            }

            for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
            {
                ProtoObj *pc = this->min_F_cell->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc);
            }
            // console.log("openArr.length = " + to_string(this->openArr.length));
            if (this->openArr.length)
            {
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
                        if (cell->F < this->min_F_cell->F)
                        {
                            break;
                        }
                    }
                }
                this->openArr.splice(md.index, 1);
                this->min_F_cell = md.cell;
                this->min_F_cell->explored = this->createCount;
            } else {
               // console.log("need way");
                unit->isPotentialWayComplite = true;
                return;
            }

            ///////////////////////////////////////////////////////

            if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell))
            {
                this->potentialWayCreate(unit, this->min_F_cell);
                break;
            }



            //  if (iter == 2555) {
            //     console.log("openArr.length = " + to_string(this->openArr.length));
            //     if (!this->min_F_cell) {
            //         console.log("no min");
            //     }
            //     unit->isPotentialWayComplite = true;
            //     return;
            //  }
        }
        //  auto end_time = std::chrono::steady_clock::now();
        //  auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        // console.log(to_string(res.count()));
        // console.log(to_string(iter));
    }
};
