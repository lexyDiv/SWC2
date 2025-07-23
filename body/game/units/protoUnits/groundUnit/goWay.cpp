#include "inFightAnimation.cpp"

void GroundUnit::goWay()
{
    if (!this->wayTakts)
    {
        if (this->isPotentialWayComplite &&
            this->potentialWay.length &&
            this->wayIndex > 0)
        {
            ProtoObj *nextCell = this->potentialWay.getItem(this->wayIndex - 1);
            bool isNeedHold = this->isNeedHoldGoWay(nextCell);
            if (this->isNextCellFreeToGoWay(nextCell) && !isNeedHold)
            {
                this->holdWayCount = 0;
                this->wayIndex--;
                this->x = this->cell->x;
                this->y = this->cell->y;
                double saveSpeedTale = this->speedTale;
                this->unitMenu->getDeltasXY(this, nextCell);
                this->cell->groundUnit = nullptr;
                this->cell = nextCell;
                this->cell->groundUnit = this;
                this->isGetMyCell = false;
                this->iAmHere();
                if (saveSpeedTale)
                {
                    this->x += cos(this->conor) * saveSpeedTale;
                    this->y += sin(this->conor) * saveSpeedTale;
                }
                this->drawIndexY = this->y;
                //  this->goWayAnimation();
            }
            else if (isNeedHold)
            {
                this->stendOnCellWait();
            }
            else
            {
                if (this->preTargetCell)
                {

                    if (this->iNeedFreeWay)
                    {
                        console.log("poshel na huy!");
                        this->stendOnCellWait();
                    }
                    else
                    {
                        this->stendOnCell();
                        this->targetObj.unit = nullptr;
                        if (this->profession != "")
                        {
                            this->updateCurrentTarget();
                            return;
                        }
                         this->getHandTarget(this->preTargetCell);
                         this->orderOnWay->isComplite = true;

                        // if (this->targetObj.unit &&
                        //     this->targetObj.unit->name == "tree")
                        // {
                        //     ProtoObj *tree = this->getAnyTree();
                        //     if (tree)
                        //     {
                        //         this->getHandTarget(tree->cell);
                        //         this->orderOnWay->isComplite = true;
                        //     }
                        //     else
                        //     {
                        //         this->targetObj.unit = nullptr;
                        //         this->profession = "";

                        //         console.log("no tree 3");
                        //     }
                        // }
                        // else
                        // {
                        //     this->targetObj.unit = nullptr;
                        //     this->getHandTarget(this->preTargetCell);
                        //     this->orderOnWay->isComplite = true;
                        // }
                    }

                    // if (this->fraction->control == "human")
                    // {
                    //     this->getHandTarget(this->preTargetCell);
                    //     this->orderOnWay->isComplite = true;
                    // }
                    // else
                    // {
                    //     if (!nextCell->groundUnit->isActive)
                    //     {
                    //         console.log("poshel na huy !!!");
                    //     }
                    //     else
                    //     {
                    //         this->getHandTarget(this->preTargetCell);
                    //         this->orderOnWay->isComplite = true;
                    //     }
                    // }
                    // return;
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
        this->holdWayCount = 0;
        //  this->goWayAnimation();
    }
};