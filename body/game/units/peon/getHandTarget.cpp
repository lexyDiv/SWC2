#include "preDraw.cpp"

void Peon::getHandTarget(ProtoObj *cell)
{
    this->preTargetCell = cell;
    this->profession = "";
    this->potentialWay.clear();
    this->wayIndex = 0;

    // if (!this->cell ||
    //     (cell->plane != this->cell->plane) ||
    //     (gu == this))
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
        // if (gu->name == "shaht")
        // {
        this->targetObj.unit = cell->groundUnit;
        this->targetObj.bornCount = cell->groundUnit->bornCount;
        // }
        this->handTargetTimer = this->handTargetMaxTime;

        if (cell->groundUnit->name == "tree")
        {
            this->profession = "lesorub";
            this->targetObjControl = this->unitMenu->targetObjControlWood;
            this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
            {
                ProtoObj *gu = cell->groundUnit;
                if (cell == this->targetCell ||
                    gu && gu->name == "tree")
                {
                    this->targetObj.unit = gu;
                    this->targetObj.bornCount = gu->bornCount;
                    return true;
                }
                return false;
            };

            this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            {
                ProtoObj *gu = cell->groundUnit;
                if (cell->plane == this->cell->plane &&
                    (!gu ||
                     gu->potentialWay.length ||
                     (gu->fraction && gu->fraction->unionCase != this->fraction->unionCase &&
                      gu->isWarrior) ||
                     cell == this->targetCell ||
                     (gu->name == "tree")))
                {
                    return true;
                }
                return false;
            };

            //   }
            // else
            // {
            //     this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            //     {
            //         if (cell->plane == this->cell->plane &&
            //             (!gu ||
            //              gu->type == "life" ||
            //              cell == this->targetCell ||
            //              (gu && gu->name == "tree")))
            //         {
            //             return true;
            //         }
            //         return false;
            //     };
            // }
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
                ProtoObj *gu = cell->groundUnit;
                if (cell == this->targetCell ||
                    gu == this->targetObj.unit)
                {
                    return true;
                }
                return false;
            };
            // if (this->fraction->control == "human")
            // {
            this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            {
                ProtoObj *gu = cell->groundUnit;
                if (cell->plane == this->cell->plane &&
                    (!gu ||
                     gu->potentialWay.length ||
                     gu == this->targetObj.unit))
                {
                    return true;
                }
                return false;
            };
            //      }
            // else
            // {
            //     this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
            //     {
            //         if (cell->plane == this->cell->plane &&
            //             (!gu ||
            //              gu->type == "life" ||
            //              gu == this->targetObj.unit))
            //         {
            //             return true;
            //         }
            //         return false;
            //     };
            // }
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
        // if (this->fraction->control == "human")
        // {
        this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
        {
            ProtoObj *gu = cell->groundUnit;
            if (cell->plane == this->cell->plane &&
                (!gu ||
                 gu->potentialWay.length ||
                 (this->targetCell->groundUnit && gu == this->targetCell->groundUnit)))
            {
                return true;
            }
            return false;
        };
        //   }
        // else
        // {
        //     this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
        //     {
        //         if (cell->plane == this->cell->plane &&
        //             (!gu ||
        //              gu->type == "life" ||
        //              (this->targetCell->groundUnit && gu == this->targetCell->groundUnit)))
        //         {
        //             return true;
        //         }
        //         return false;
        //     };
        // }
    }
    //  this->getCurrentTargetCell(cell);
    this->game->unitsOnWay.push(this);
    if (!this->isActive)
    {
        this->isActive = true;
        this->fraction->activeUnits.push(this);
    }
};