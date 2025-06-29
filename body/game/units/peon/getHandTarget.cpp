#include "getTreeNear.cpp"

void Peon::getHandTarget(ProtoObj *cell)
{
    this->preTargetCell = cell;
    // this->profession = "";
    this->potentialWay.clear();
    this->wayIndex = 0;

    this->isPotentialWayComplite = false;
    this->targetCell = nullptr;
    this->targetObjControl = this->unitMenu->targetObjControl;
    this->targetObj.unit = nullptr;

    if (cell->groundUnit)
    {

        this->targetObj.unit = cell->groundUnit;
        this->targetObj.bornCount = cell->groundUnit->bornCount;

        // this->handTargetTimer = this->handTargetMaxTime;

        if (cell->groundUnit->name == "tree")
        {
            if (this->wood)
            {
                ProtoObj *base = this->getBaseForUnloading();
                if (base)
                {
                    this->getHandTarget(base->cell);
                    return;
                }
            }
            // this->profession = "lesorub";
            this->targetObjControl = this->fraction->control == "" ? this->unitMenu->targetObjControlWoodComp : this->unitMenu->targetObjControlWood;
            this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
            {
                ProtoObj *gu = cell->groundUnit;
                if (
                    gu && gu->name == "tree")
                {
                    this->targetObj.unit = gu;
                    this->targetObj.bornCount = gu->bornCount;
                    return true;
                }
                return false;
            };

            if (!this->iNeedFreeWay)
            {
                this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
                {
                    ProtoObj *gu = cell->groundUnit;
                    ProtoObj *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->potentialWay.length ||
                         (gu->fraction && gu->fraction->unionCase != this->fraction->unionCase &&
                          gu->isWarrior) ||
                         (gu->name == "tree" && !gu->lesorub)))
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
                    ProtoObj *gu = cell->groundUnit;
                    ProtoObj *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->type == "life" ||
                         gu->name == "tree" && !gu->lesorub))
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
                //  this->profession = "shahter";
                if (this->gold > 0)
                {
                    ProtoObj *base = this->getBaseForUnloadingGold();
                    if (base)
                    {
                        this->getHandTarget(base->cell);
                        return;
                    }
                }
            };
            if (cell->groundUnit->type != "life")
            {
                this->targetObjControl = this->fraction->control == "" ? this->unitMenu->targetObjControlBuildingComp : this->unitMenu->targetObjControlBuilding;
            }
            this->isOnGetPotentialWayGetTarget = [this](ProtoObj *cell)
            {
                ProtoObj *gu = cell->groundUnit;
                if ( // cell == this->targetCell ||
                    gu == this->targetObj.unit)
                {
                    return true;
                }
                return false;
            };

            if (!this->iNeedFreeWay)
            {
                this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
                {
                    ProtoObj *gu = cell->groundUnit;
                    ProtoObj *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->potentialWay.length ||
                         gu == this->targetObj.unit))
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
                    ProtoObj *gu = cell->groundUnit;
                    ProtoObj *tc = this->cell;
                    if (tc &&
                        cell->plane == tc->plane &&
                        (!gu ||
                         gu->type == "life" ||
                         gu == this->targetObj.unit))
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

        this->isNewCellOnGetWayValide = [this](ProtoObj *cell)
        {
            ProtoObj *gu = cell->groundUnit;
            ProtoObj *tc = this->cell;
            if (tc &&
                cell->plane == tc->plane &&
                (!gu ||
                 gu->potentialWay.length))
            {
                return true;
            }
            return false;
        };
    }

    // if (this->cell && this->cell->game->unitsOnWay.indexOf(this) == -1)
    // {
    //     this->game->unitsOnWay.push(this);
    // }
    if (!this->isActive)
    {
        this->isActive = true;
        this->fraction->activeUnits.push(this);
    }
};