#include "isNewCellOnGetWayValide.cpp"

bool isBlocked(ProtoObj *cell, ProtoObj *unit)
{
    for (int i = 0; i < cell->aroundCells.length; i++)
    {
        ProtoObj *ac = cell->aroundCells.getItem(i);
        if (!ac->groundUnit || ac->groundUnit->way.length ||
            (unit->profession == "lesorub" && ac->groundUnit->name == "tree"))
        {
            return false;
        }
    }
    return true;
};

void Peon::getCurrentTargetCell()
{
    this->gf->procCurr += 0.0001;
    Array<ProtoObj *> acs;
    Array<ProtoObj *> freeCells;

    this->preTargetCell->procCurr = this->gf->procCurr;
    if (!this->preTargetCell->groundUnit)
    {
        acs.push(this->preTargetCell);
    }
    else
    {
        if (!this->preTargetCell->groundUnit->isBlockedd(this))
        {
            //  console.log("here");

            if (this->preTargetCell->groundUnit->type == "building")
            {
                int randIndex = intRand(0, this->preTargetCell->groundUnit->myCells.length);
                this->targetCell = this->preTargetCell->groundUnit->myCells.getItem(randIndex);
            }
            else
            {
                this->targetCell = this->preTargetCell->groundUnit->cell;
            }
            return;
        }
        else
        {
            if (preTargetCell->groundUnit->contactCells.length)
            {
                this->preTargetCell->groundUnit->contactCells.forEach([this, &acs](ProtoObj *cell)
                                                                      {
            cell->procCurr = this->gf->procCurr;
            acs.push(cell); });
            }
            else
            {
                this->preTargetCell->groundUnit->cell->aroundCells.forEach([this, &acs](ProtoObj *cell)
                                                                           {
            cell->procCurr = this->gf->procCurr;
            acs.push(cell); });
            }
        }
    }
    int iter = 0;

    while (iter < 1000)
    {
        Array<ProtoObj *> newAcs;
        for (int i = 0; i < acs.length; i++)
        {
            ProtoObj *c = acs.getItem(i);
            if ((!c->groundUnit || c->groundUnit->way.length ||
                 (this->profession == "lesorub" && c->groundUnit->name == "tree")) &&
                (!isBlocked(c, this) || c == this->preTargetCell))
            {
                freeCells.push(c);
            }
            c->aroundCells.forEach([this, &newAcs](ProtoObj *cl)
                                   {
              if (cl->procCurr != this->gf->procCurr) {
                cl->procCurr = this->gf->procCurr;
                newAcs.push(cl);
              } });
        }
        acs.copy(newAcs);
        if (freeCells.length)
        {
            double dis = 10000000;
            int index = 0;
            //  this->preTargetCell = !this->preTargetCell->groundUnit ? this->preTargetCell : this->preTargetCell->groundUnit->cell;
            ProtoObj *tc = nullptr;
            if (this->preTargetCell->groundUnit)
            {
                tc = this->preTargetCell->groundUnit->cell;
            }
            else
            {
                tc = this->preTargetCell;
            }
            for (int i = 0; i < freeCells.length; i++)
            {
                ProtoObj *fc = freeCells.getItem(i);
                // console.log(to_string(freeCells.length));
                Delta delta = getDeltas(
                    {x : fc->x, y : fc->y},
                    {x : tc->x, y : tc->y});
                double currentDis = getDis(delta);
                if (dis > currentDis)
                {
                    dis = currentDis;
                    index = i;
                }
            }
            this->targetCell = freeCells.getItem(index);
            return;
        }
    }
    this->targetCell = this->preTargetCell;
};

///////////////////////////

bool isBlocked2(ProtoObj *cell, ProtoObj *unit)
{
    for (int i = 0; i < cell->aroundCells.length; i++)
    {
        ProtoObj *ac = cell->aroundCells.getItem(i);
        if (!ac->groundUnit || ac->groundUnit->way.length ||
            (unit->profession == "lesorub" && ac->groundUnit->name == "tree"))
        {
            return false;
        }
    }
    return true;
};

void Peon::getCurrentTargetCell2()
{
    this->gf->procCurr2 += 0.0001;
    Array<ProtoObj *> acs;
    Array<ProtoObj *> freeCells;

    this->preTargetCell->procCurr2 = this->gf->procCurr2;
    if (!this->preTargetCell->groundUnit)
    {
        acs.push(this->preTargetCell);
    }
    else
    {
        if (!this->preTargetCell->groundUnit->isBlockedd(this))
        {
            //  console.log("here");
            this->targetCell = this->preTargetCell->groundUnit->cell;
            return;
        }
        else
        {
            if (preTargetCell->groundUnit->contactCells.length)
            {
                this->preTargetCell->groundUnit->contactCells.forEach([this, &acs](ProtoObj *cell)
                                                                      {
            cell->procCurr2 = this->gf->procCurr2;
            acs.push(cell); });
            }
            else
            {
                this->preTargetCell->groundUnit->cell->aroundCells.forEach([this, &acs](ProtoObj *cell)
                                                                           {
            cell->procCurr2 = this->gf->procCurr2;
            acs.push(cell); });
            }
        }
    }
    int iter = 0;

    while (iter < 1000)
    {
        Array<ProtoObj *> newAcs;
        for (int i = 0; i < acs.length; i++)
        {
            ProtoObj *c = acs.getItem(i);
            if ((!c->groundUnit || c->groundUnit->way.length ||
                 (this->profession == "lesorub" && c->groundUnit->name == "tree")) &&
                (!isBlocked2(c, this) || c == this->preTargetCell))
            {
                freeCells.push(c);
            }
            c->aroundCells.forEach([this, &newAcs](ProtoObj *cl)
                                   {
              if (cl->procCurr2 != this->gf->procCurr2) {
                cl->procCurr2 = this->gf->procCurr2;
                newAcs.push(cl);
              } });
        }
        acs.copy(newAcs);
        if (freeCells.length)
        {
            double dis = 10000000;
            int index = 0;
            //  this->preTargetCell = !this->preTargetCell->groundUnit ? this->preTargetCell : this->preTargetCell->groundUnit->cell;
            ProtoObj *tc = nullptr;
            if (this->preTargetCell->groundUnit)
            {
                tc = this->preTargetCell->groundUnit->cell;
            }
            else
            {
                tc = this->preTargetCell;
            }
            for (int i = 0; i < freeCells.length; i++)
            {
                ProtoObj *fc = freeCells.getItem(i);
                // console.log(to_string(freeCells.length));
                Delta delta = getDeltas(
                    {x : fc->x, y : fc->y},
                    {x : tc->x, y : tc->y});
                double currentDis = getDis(delta);
                if (dis > currentDis)
                {
                    dis = currentDis;
                    index = i;
                }
            }
            this->targetCell = freeCells.getItem(index);
            return;
        }
    }
    this->targetCell = this->preTargetCell;
};