#include "getHandTarget.cpp"

bool Peon::isOnGetPotentialWayGetTarget(ProtoObj *cell)
{
    ProtoObj *tc = this->targetCell;
    if (tc->groundUnit)
    {
       // Array<ProtoObj *> potentialFinishCells;
        for (int i = 0; i < cell->aroundCells.length; i++)
        {
            ProtoObj *ac = cell->aroundCells.getItem(i);
            if (ac->groundUnit &&
                ((ac->groundUnit == tc->groundUnit) ||
                 (this->profession == "lesorub" &&
                  ac->groundUnit->name == "tree")))
            {
                return true;
            }
        }
    }
    if (tc == cell)
    {
        return true;
    }
    return false;
};