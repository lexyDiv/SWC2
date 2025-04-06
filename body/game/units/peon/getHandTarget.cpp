#include "preDraw.cpp"

void Peon::getHandTarget(ProtoObj *cell)
{
    this->targetCell = cell;
    this->profession = "";
    this->way.clear();
    if (!this->cell ||
        (cell->plane != this->cell->plane))
    {
        return;
    }

    //  this->targetCell = cell->groundUnit ? cell->groundUnit->cell : cell;
 
    // this->handTargetTimer = this->handTargetMaxTime;
    this->isPotentialWayComplite = false;
    this->isNeedReturnGetPotentialWay = true;

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
                 cell == this->targetCell))
            {
                return true;
            }
            return false;
        };
    }
  //  this->getCurrentTargetCell(cell);
    this->game->unitsOnWay.push(this);
};