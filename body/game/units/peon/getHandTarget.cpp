#include "preDraw.cpp"

void Peon::getHandTarget(ProtoObj *cell)
{
    this->preTargetCell = cell;
    this->profession = "";
    this->potentialWay.clear();
    this->wayIndex = 0;

    // if (!this->cell ||
    //     (cell->plane != this->cell->plane) ||
    //     (cell->groundUnit == this))
    // {
    //     return;
    // }



    // this->handTargetTimer = this->handTargetMaxTime;
    this->isPotentialWayComplite = false;
   // this->isNeedReturnGetPotentialWay = true;
    this->targetCell = nullptr;


    if (cell->groundUnit)
    {
        if (cell->groundUnit->name == "tree")
        {
            this->profession = "lesorub";
            this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
            {
                if (cell == this->targetCell ||
                    cell->groundUnit && cell->groundUnit->name == "tree")
                {
                    return true;
                }
                return false;
            };
            this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            {
                if (cell->plane == this->cell->plane &&
                    (!cell->groundUnit ||
                     cell == this->targetCell ||
                     (cell->groundUnit && cell->groundUnit->name == "tree")))
                {
                    return true;
                }
                return false;
            };
        }
        else
        {
            if (cell->groundUnit->name == "shaht")
            {
                this->profession = "shahter";
            };
            this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
            {
                if (cell == this->targetCell)
                {
                    return true;
                }
                return false;
            };
            this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            {
                if (cell->plane == this->cell->plane &&
                    (!cell->groundUnit ||
                     cell->groundUnit->way.length))
                {
                    return true;
                }
                return false;
            };
        }
    }
    else
    {
        this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
        {
            if (cell == this->targetCell)
            {
                return true;
            }
            return false;
        };
        this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
        {
            if (cell->plane == this->cell->plane &&
                (!cell->groundUnit ||
                 (this->targetCell->groundUnit && cell->groundUnit == this->targetCell->groundUnit)))
            {
                return true;
            }
            return false;
        };
    }
    //  this->getCurrentTargetCell(cell);
    this->game->unitsOnWay.push(this);
    if (!this->isActive) {
        this->isActive = true;
        this->fraction->activeUnits.push(this);
    }
};