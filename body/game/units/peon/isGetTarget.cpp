#include "goWay.cpp"

bool Peon::isGetTarget()
{
    ProtoObj *to = this->targetObj.unit;
    if (!this->holdWayCount &&
        this->targetCell// &&
       // !to &&
      //  !this->wayTakts &&
        // this->potentialWay.length &&
       // this->wayIndex <= 5 &&
      //  this->isPotentialWayComplite
        )
    {
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
                        //this->targetObj.unit = cell->groundUnit;
                       // this->targetObj.bornCount = cell->groundUnit->bornCount;
                      //  this->gettingTarget = cell->groundUnit;
                        this->iNeedFreeWay = false;
                        this->isIgetMyTarget = true;
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
                        this->isIgetMyTarget = true;
                       // this->gettingTarget = cell->groundUnit;
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
                this->isIgetMyTarget = true;
                return true;
            }
        }
    }
    return false;
};
