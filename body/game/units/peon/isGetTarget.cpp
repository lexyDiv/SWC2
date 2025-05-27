#include "goWay.cpp"

bool Peon::isGetTarget()
{
    if (!this->holdWayCount &&
        this->targetCell &&
        !this->wayTakts &&
        this->potentialWay.length &&
        this->wayIndex <= 5 &&
        this->isPotentialWayComplite)
    {
        ProtoObj *to = this->targetObj.unit;
        if (to)
        {
            if (to->name == "tree")
            {
                for (int i = 0; i < this->cell->aroundCells.length; i++)
                {
                    ProtoObj *cell = this->cell->aroundCells.getItem(i);
                    if (cell->groundUnit &&
                        cell->groundUnit->name == "tree" &&
                        !cell->groundUnit->lesorub)
                    {
                        this->iNeedFreeWay = false;
                        return true;
                    }
                }
            }
            else
            {
                for (int i = 0; i < this->cell->aroundCells.length; i++)
                {
                    ProtoObj *cell = this->cell->aroundCells.getItem(i);
                    if (cell->groundUnit && cell->groundUnit == to)
                    {
                        this->iNeedFreeWay = false;
                        return true;
                    }
                }
            }
        }
        else
        {
            if (this->cell == this->targetCell ||
                (this->wayIndex == 1 &&
                 this->potentialWay.getItem(0)->groundUnit))
            {
                this->iNeedFreeWay = false;
                return true;
            }
        }
    }
    return false;
};
