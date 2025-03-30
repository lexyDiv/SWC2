#include "preDraw.cpp"

void Peon::getHandTarget(ProtoObj *cell)
{
    // this->handTargetCell = cell;
    // this->handTargetTimer = 200;
    //       this->isPotentialWayComplite = false;
    // this->game->unitsOnWay.push(this);
    ////////////////////////////////////////////////////////
    this->profession = "";
    this->way.clear();
    if (!this->cell ||
        (cell->plane != this->cell->plane))
    {
        return;
    }

    if (cell->groundUnit)
    {
        if (cell->groundUnit->name == "tree")
        {
            this->profession = "lesorub";
        }
    }

    this->targetCell = cell;
    //this->handTargetTimer = this->handTargetMaxTime;
    this->isPotentialWayComplite = false;
    this->isNeedReturnGetPotentialWay = true;
    this->game->unitsOnWay.push(this);
};
