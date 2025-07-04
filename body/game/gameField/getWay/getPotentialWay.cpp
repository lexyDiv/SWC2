#include "get_G.cpp"

// bool hardReady = true;
// bool goWorkReady = true;
bool needReturn = false;
// bool needReturn = false;
int hold = 0;

ProtoObj *hzCell = nullptr;

void GameField::getPotentialWay(ProtoObj *unit)
{
    if (needReturn)
    {
        return;
    }
    // if (unit->focus) {
    //     console.log("scan now");
    // }
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
            if (needReturn)
            {
                return;
            }
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

            if (this->openArr.length && iter < 10000)
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

void GameField::getPotentialWay2(ProtoObj *unit)
{
    if (needReturn)
    {
        return;
    }
    // if (unit->focus) {
    //     console.log("scan now");
    // }
    // auto start_time = std::chrono::steady_clock::now();
    // console.log("scan way");

    // if (unit->isPotentialWayComplite) {
    //     console.log("unit->isPotentialWayComplite");
    //     return;
    // }

    // unit->potentialWay.clear();
    // unit->isNeedReturnGetPotentialWay = false;
    unit->getCurrentTargetCell2();
    // unit->targetCell = unit->preTargetCell;

    if (
        unit->hp > 0)
    {

        this->createCount2 += 0.001;
        if (this->createCount2 >= 100000000)
        {
            this->createCount2 = 0;
            console.log("default");
        }
        unit->cell->createCountData2 = this->createCount2;
        this->openArr2.clear();
        this->min_F_cell2 = unit->cell;
        this->min_F_cell2->F2 = 0;
        this->min_F_cell2->H2 = 0;
        this->min_F_cell2->G2 = 0;
        this->globalMin_H_cell2 = nullptr;

        int iter = 0;

        ///////////////////////////  poka tak!
        unit->cell->aroundCells.forEach([this, unit](ProtoObj *cell)
                                        {
            if (cell->groundUnit 
            && cell->groundUnit != unit->targetCell->groundUnit
            ) {
                cell->explored2 = this->createCount2;
            } });
        ///////////////////////

        while (true)
        {
            if (needReturn)
            {
                return;
            }
            iter++;
            // console.log(to_string(iter));
            MinData md;

            if ((unit->orderOnWay && !unit->orderOnWay->isComplite))
            {
                unit->isPotentialWayComplite = true;
                return;
            }

            for (int i = 0; i < this->min_F_cell2->aroundCells.length; i++)
            {
                ProtoObj *pc = this->min_F_cell2->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr2(unit, this->min_F_cell2, pc);
            }

            if (this->openArr2.length && iter < 10000)
            {
                int index = this->openArr2.length - 1;
                md.cell = this->openArr2.getItem(this->openArr2.length - 1);
                md.index = index;
                for (int i = index; i >= 0; i--)
                {
                    ProtoObj *cell = this->openArr2.getItem(i);
                    if (md.cell->F2 >= cell->F2)
                    {
                        md.cell = cell;
                        md.index = i;
                        if (cell->F2 < this->min_F_cell2->F2)
                        {
                            break;
                        }
                    }
                }
                this->openArr2.splice(md.index, 1);

                this->min_F_cell2 = md.cell;
                this->min_F_cell2->explored2 = this->createCount2;
                if (!this->globalMin_H_cell2 || this->globalMin_H_cell2->H2 > this->min_F_cell2->H2)
                {
                    this->globalMin_H_cell2 = this->min_F_cell2;
                }
            }
            else
            {
                unit->isPotentialWayComplite = true;
                if (!this->globalMin_H_cell2)
                {
                    unit->isPotentialWayComplite = true;
                }
                else
                {
                    this->potentialWayCreate2(unit, this->globalMin_H_cell2);
                    unit->targetCell = this->globalMin_H_cell2;
                }
                return;
            }

            ///////////////////////////////////////////////////////

            if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell2))
            {
                this->potentialWayCreate2(unit, this->min_F_cell2);

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