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
    this->targetObjControl = this->unitMenu->targetObjControl;

    if (cell->groundUnit)
    {
        // if (cell->groundUnit->name == "shaht")
        // {
        this->targetObj = cell->groundUnit;
        // }
        this->handTargetTimer = this->handTargetMaxTime;

        if (cell->groundUnit->name == "tree")
        {
            this->profession = "lesorub";
            this->targetObjControl = this->unitMenu->targetObjControlWood;
            this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
            {
                if (cell == this->targetCell ||
                    cell->groundUnit && cell->groundUnit->name == "tree")
                {
                    this->targetObj = cell->groundUnit;
                    return true;
                }
                return false;
            };
            if (this->fraction->control == "human")
            {
                this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
                {
                    if (cell->plane == this->cell->plane &&
                        (!cell->groundUnit ||
                         cell->groundUnit->potentialWay.length ||
                         (cell->groundUnit->fraction->unionCase != this->fraction->unionCase &&
                          cell->groundUnit->isWarrior) ||
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
                this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
                {
                    if (cell->plane == this->cell->plane &&
                        (!cell->groundUnit ||
                         cell->groundUnit->type == "life" ||
                         cell == this->targetCell ||
                         (cell->groundUnit && cell->groundUnit->name == "tree")))
                    {
                        return true;
                    }
                    return false;
                };
            }
        }
        else
        {
            if (cell->groundUnit->name == "shaht")
            {
                this->profession = "shahter";
                this->targetObjControl = this->unitMenu->targetObjControlGold;
            };
            this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
            {
                if (cell == this->targetCell ||
                    cell->groundUnit == this->targetObj)
                {
                    return true;
                }
                return false;
            };
            if (this->fraction->control == "human")
            {
                this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
                {
                    if (cell->plane == this->cell->plane &&
                        (!cell->groundUnit ||
                         cell->groundUnit->potentialWay.length ||
                         cell->groundUnit == this->targetObj))
                    {
                        return true;
                    }
                    return false;
                };
            }
            else
            {
                this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
                {
                    if (cell->plane == this->cell->plane &&
                        (!cell->groundUnit ||
                         cell->groundUnit->type == "life" ||
                         cell->groundUnit == this->targetObj))
                    {
                        return true;
                    }
                    return false;
                };
            }
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
        if (this->fraction->control == "human")
        {
            this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            {
                if (cell->plane == this->cell->plane &&
                    (!cell->groundUnit ||
                     cell->groundUnit->potentialWay.length ||
                     (this->targetCell->groundUnit && cell->groundUnit == this->targetCell->groundUnit)))
                {
                    return true;
                }
                return false;
            };
        }
        else
        {
            this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            {
                if (cell->plane == this->cell->plane &&
                    (!cell->groundUnit ||
                     cell->groundUnit->type == "life" ||
                     (this->targetCell->groundUnit && cell->groundUnit == this->targetCell->groundUnit)))
                {
                    return true;
                }
                return false;
            };
        }
    }
    //  this->getCurrentTargetCell(cell);
    this->game->unitsOnWay.push(this);
    if (!this->isActive)
    {
        this->isActive = true;
        this->fraction->activeUnits.push(this);
    }
};