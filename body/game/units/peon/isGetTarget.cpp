#include "goWay.cpp"

bool Peon::isGetTarget()
{
    if (!this->holdWayCount &&
        this->targetCell &&
        !this->wayTakts &&
        this->potentialWay.length &&
        this->wayIndex <= 2 &&
        this->isPotentialWayComplite)
    {
        if (this->profession == "lesorub")
        {
            for (int i = 0; i < this->cell->aroundCells.length; i++)
            {
                ProtoObj *cell = this->cell->aroundCells.getItem(i);
                if (cell->groundUnit &&
                    cell->groundUnit->name == "tree" &&
                    !cell->groundUnit->lesorub)
                {
                    return true;
                }
            }
        }
        else if (this->profession == "shahter")
        {
            for (int i = 0; i < this->cell->aroundCells.length; i++)
            {
                ProtoObj *cell = this->cell->aroundCells.getItem(i);
                if (cell->groundUnit && cell->groundUnit == this->targetObj.unit)
                {
                    return true;
                }
            }
        }
        else
        {
            if (this->cell == this->targetCell ||
                (this->wayIndex == 1 &&
                 this->potentialWay.getItem(0)->groundUnit))
            {
                return true;
            }
        }
    }
    return false;
};