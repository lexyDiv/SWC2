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
        this->isQuick = false;
        this->min_F_cell = nullptr;

        int iter = 0;
      //  auto start_time = std::chrono::steady_clock::now();
        while (true)
        {
            iter++;

            MinData md;

            this->quickArr.clear();

            if (!this->isQuick)
            {
                if (this->openArr.length)
                {
                    md = this->openArr.getMinData([](ProtoObj *cell)
                                                  { return cell->F; });
                    this->min_F_cell = md.cell;
                    this->openArr.splice(md.index, 1);
                }
            }

            this->isQuick = false;

            for (int i = 0; i < this->min_F_cell->aroundCells.length; i++)
            {
                ProtoObj *pc = this->min_F_cell->aroundCells.getItem(i);
                this->exploreNewCellAndAddToOpenArr(unit, this->min_F_cell, pc, finishCell);
                if (unit->isPotentialWayComplite)
                {
                    break;
                }
            }

            if (this->quickArr.length)
            {
                md = this->quickArr.getMinData([](ProtoObj *cell)
                                               { return cell->F; });
                if (md.cell->F <= this->min_F_cell->F)
                {
                    this->isQuick = true;
                    this->min_F_cell = md.cell;
                }
            }

            this->quickArr.forEach([this](ProtoObj *c)
                                   {
                if (c != this->min_F_cell) {
                    this->openArr.push(c);
                } });

            if (!this->quickArr.length && !this->openArr.length)
            {
                unit->isPotentialWayComplite = true;
            }
            if (unit->isPotentialWayComplite)
            {
                break;
            }
        }
        // auto end_time = std::chrono::steady_clock::now();
        // auto res = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        // console.log(to_string(res.count()));
        // console.log(to_string(iter));
    }
};