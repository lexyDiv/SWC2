#include "get_G.cpp"



ProtoObj *hzCell = nullptr;

void GameField::getPotentialWay(ProtoObj *unit)
{

    if (unit->focus) {
        console.log("scan now");
    }
    // auto start_time = std::chrono::steady_clock::now();
    // console.log("scan way");

    // if (unit->isPotentialWayComplite) {
    //     console.log("unit->isPotentialWayComplite");
    //     return;
    // }


   // unit->potentialWay.clear();
    // unit->isNeedReturnGetPotentialWay = false;
    unit->getCurrentTargetCell();
    // unit->targetCell = unit->preTargetCell;

    if (
        unit->hp > 0)
    {

        this->createCount += 0.001;
        if (this->createCount >= 100000000)
        {
            this->createCount = 0;
            console.log("default");
        }
        unit->cell->createCountData = this->createCount;
        this->openArr.clear();
        this->min_F_cell = unit->cell;
        this->min_F_cell->F = 0;
        this->min_F_cell->H = 0;
        this->min_F_cell->G = 0;
        this->globalMin_H_cell = nullptr;

        int iter = 0;

        ///////////////////////////  poka tak!
        unit->cell->aroundCells.forEach([this, unit](ProtoObj *cell)
                                        {
            if (cell->groundUnit 
            && cell->groundUnit != unit->targetCell->groundUnit
            ) {
                cell->explored = this->createCount;
            } });
        ///////////////////////

        while (true)
        {
            iter++;
            // console.log(to_string(iter));
            MinData md;

            if ((unit->orderOnWay && !unit->orderOnWay->isComplite))
            {
                unit->isPotentialWayComplite = true;
                return;
            }

            for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
            {
                ProtoObj *pc = this->min_F_cell->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc);
            }

            if (this->openArr.length && iter < 5000)
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
                if (!this->globalMin_H_cell || this->globalMin_H_cell->H > this->min_F_cell->H)
                {
                    this->globalMin_H_cell = this->min_F_cell;
                }
            }
            else
            {
                unit->isPotentialWayComplite = true;
                if (!this->globalMin_H_cell)
                {
                    unit->isPotentialWayComplite = true;
                }
                else
                {
                    this->potentialWayCreate(unit, this->globalMin_H_cell);
                    unit->targetCell = this->globalMin_H_cell;
                }
                return;
            }

            ///////////////////////////////////////////////////////

            if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell))
            {
                this->potentialWayCreate(unit, this->min_F_cell);

                break;
            }

            //  if (iter == 4000) {
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
