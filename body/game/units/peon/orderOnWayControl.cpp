#include "activeProg.cpp"

void Peon::orderOnWayControl()
{
    if (this->orderOnWay && !this->orderOnWay->isComplite)
    {
        ProtoObj *oCell = this->orderOnWay->cell;
        if (!this->cell ||
            (oCell->plane != this->cell->plane) ||
            (oCell->groundUnit == this))
        {

            this->orderOnWay->isComplite = true;
            return;
        }

        if (this->isPotentialWayComplite)
        {
            this->getHandTarget(oCell);

            this->orderOnWay->isComplite = true;
        }
    }
};