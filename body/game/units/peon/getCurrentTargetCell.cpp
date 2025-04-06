#include "isNewCellOnGetWayValide.cpp"

double procCurr = 0.0;

bool isBlocked(ProtoObj *cell)
{
    for (int i = 0; i < cell->aroundCells.length; i++)
    {
        ProtoObj *ac = cell->aroundCells.getItem(i);
        if (!ac->groundUnit || ac->groundUnit->way.length)
        {
            return false;
        }
    }
    return true;
}

void Peon::getCurrentTargetCell()
{
    procCurr += 0.0000001;
    Array<ProtoObj *> acs;
    Array<ProtoObj *> freeCells;
    ProtoObj *cell = this->targetCell;
    if (!cell->groundUnit)
    {
        acs.push(cell);
    }
    else
    {
        cell->groundUnit->contactCells.forEach([&acs](ProtoObj* cell){
            acs.push(cell);
        });
    }
     int iter = 0;
    while (true)
    {
         iter++;
        for (int i = 0; i < acs.length; i++)
        {
            ProtoObj *c = acs.getItem(i);
            if ((!c->groundUnit || c->groundUnit->way.length) && !isBlocked(c))
            {
                freeCells.push(c);
            }
            c->procCurr = procCurr;
        }
        if (freeCells.length)
        {
            double dis = 10000000;
            int index = 0;
            cell = !cell->groundUnit ? cell : cell->groundUnit->cell;
            for (int i = 0; i < freeCells.length; i++)
            {
                ProtoObj *c = freeCells.getItem(i);
                Delta delta = getDeltas(
                    {x : c->x, y : c->y},
                    {x : cell->x, y : cell->y});
                double currentDis = getDis(delta);
                if (dis > currentDis)
                {
                    dis = currentDis;
                    index = i;
                }
            }
            this->targetCell = freeCells.getItem(index);
            console.log("new iter = " + to_string(iter));
            return;
        }
        Array<ProtoObj *> newAcs;
        for (int i = 0; i < acs.length; i++)
        {
            ProtoObj *c = acs.getItem(i);
            c->aroundCells.forEach([&newAcs](ProtoObj *ac)
                                   { newAcs.push(ac); });
        }
        acs.copy(newAcs);
    }
};