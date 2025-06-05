#include "selectAnAction.cpp"

void Peon::preDraw()
{
    this->isAddOnDraw = false;
    if (!this->isActive && !this->inSave)
    {
        this->animTimer++;
        if (this->animTimer == 150)
        {
            this->animX = intRand(0, 8) * this->animGabX;
            this->animTimer = 0;
        }
    }
    else
    {
        if (!this->isGetMyCell || this->inSave)
        {
            this->goWayAnimation();
        }
        else if (this->inFight)
        {
            this->inFightAnimation();
        }
    }
};