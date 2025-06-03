#include "GroundUnit.cpp"

void GroundUnit::orderOnWayControl()
{
    if (this->orderOnWay && !this->orderOnWay->isComplite)
    {
        ProtoObj *oCell = this->orderOnWay->cell;
        ProtoObj *finishCell = this->potentialWay.length ? this->potentialWay.getItem(0) : nullptr;
        ProtoObj *tarObj = this->targetObj.unit ? this->targetObj.unit : nullptr;
     if (!this->cell ||
            (oCell->plane != this->cell->plane) ||
            (oCell->groundUnit == this) ||
            (finishCell == oCell) ||
            (tarObj && tarObj == oCell->groundUnit)
            )
        {
          //  console.log("return");
            this->orderOnWay->isComplite = true;
            return;
        }

        if (this->isPotentialWayComplite)
        {
            this->getHandTarget(oCell);

            this->orderOnWay->isComplite = true;
        }
        this->iNeedFreeWay = false;
    }
};