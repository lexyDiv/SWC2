#include "goWayAnimation.cpp"

void Peon::goWay()
{
    if (!this->wayTakts)
    {
        if (this->isPotentialWayComplite &&
            this->potentialWay.length &&
            this->wayIndex > 0)
        {
            ProtoObj *nextCell = this->potentialWay.getItem(this->wayIndex - 1);
            if (this->isNextCellFreeToGoWay(nextCell))
            {
                this->wayIndex--;
                this->x = this->cell->x;
                this->y = this->cell->y;
                double saveSpeedTale = this->speedTale;
                this->unitMenu->getDeltasXY(this, nextCell);
                this->cell->groundUnit = nullptr;
                this->cell = nextCell;
                this->cell->groundUnit = this;
                this->isGetMyCell = false;
                if (saveSpeedTale)
                {
                    this->x += cos(this->conor) * saveSpeedTale;
                    this->y += sin(this->conor) * saveSpeedTale;
                }
                this->drawIndexY = this->y;
                this->goWayAnimation();
            }
            else if (this->isNeedHoldGoWay(nextCell))
            {
                this->stendOnCellWait();
                console.log("hold");
            }
            else
            {
                this->stendOnCell();
                if (this->preTargetCell)
                {
                    // std::cout<<"NEW WAY"<<std::endl;
                    console.log("new way");
                    this->getHandTarget(this->preTargetCell);

                    this->orderOnWay->isComplite = true;
                    return;
                }
            }
        }
        else
        {
            this->stendOnCell();
        }
    }
    else if (this->wayTakts)
    {
        this->x += this->wayDeltaX;
        this->y += this->wayDeltaY;
        this->drawIndexY = this->y;
        this->wayTakts--;
        this->goWayAnimation();
    }
}