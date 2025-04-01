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

        this->quickArr.clear();
        this->isQuick = false;
        this->min_F_cell = startCell;

        int iter = 0;
        auto start_time = std::chrono::steady_clock::now();

        while (true)
        {
            iter++;

            MinData md;


            for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
            {
                ProtoObj *pc = this->min_F_cell->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc, finishCell);
                if (unit->isPotentialWayComplite)
                {
                    break;
                }
            }

            // this->exp.clear();
            // this->openArr.forEach([this](ProtoObj* cell, int i){
            //     if (i % 3 == 0) {
            //         Array<ProtoObj* > arr;
            //         this->exp.push(arr);
            //     }
            //     this->exp.getItem3(this->exp.length - 1).push(cell);
            // });

            // MinData expM;
            // for (int i = 0; i < this->exp.length; i++) {
            //     Array<ProtoObj* > &arr = this->exp.getItem3(i);
            //     for (int k = 0; k < arr.length; k ++) {
            //         ProtoObj* cell = arr.getItem(k);
            //         if (!expM.cell || expM.cell->F > cell->F) {
            //             expM.cell = cell;
            //             expM.i = i;
            //             expM.k = k;
            //         }
            //     }
            // }

            //////////////////////////////////////////////////////////
            // if (this->openArr.length)
            // {
            //     md = this->openArr.getMinData([](ProtoObj *cell)
            //                                   { return cell->F; });
            //     this->min_F_cell = md.cell;
            //     this->openArr.splice(md.index, 1);
            // }

          bool brc = false;
          int it = 0;
            for (int i = this->openArr.length - 1; i >= 0; i--)
            {
                it ++;
                ProtoObj *cell = this->openArr.getItem(i);
                if (!md.cell || md.cell->F >= cell->F)
                {
                    md.cell = cell;
                    md.index = i;
                    if (it <= 8 && md.cell->F <= this->min_F_cell->F) {
                        brc = true;
                        console.log("quick");
                        break;
                    }
                }
                if (brc) {
                    break;
                }
            }


            // for (int i = 0; i < this->openArr.length; i++)
            // {
            //     ProtoObj *cell = this->openArr.getItem(i);
            //     if (!md.cell || md.cell->F > cell->F)
            //     {
            //         md.cell = cell;
            //         md.index = i;
            //     }
            // } // is ok!

            this->min_F_cell = md.cell;
            this->openArr.splice(md.index, 1);
            ///////////////////////////////////////////////////////

            // if (md.cell != expM.cell) {
            //     console.log("!=");
            //     console.log("md.cell->F = " + to_string(md.cell->F) + " expM.cell->F = " + to_string(expM.cell->F));
            // }

            if (unit->isOnGetPotentialWayGetTarget(this->min_F_cell) ||
                unit->isNeedReturnGetPotentialWay)
            {
                if (!unit->isNeedReturnGetPotentialWay)
                {
                    this->potentialWayCreate(unit, this->min_F_cell);
                }
                // return;
                break;
            }

            if (!this->quickArr.length && !this->openArr.length)
            {
                unit->isPotentialWayComplite = true;
            }
            if (unit->isPotentialWayComplite)
            {
                break;
            }
        }
        auto end_time = std::chrono::steady_clock::now();
        auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
         console.log(to_string(res.count()));
       // console.log(to_string(iter));
    }
};
