#include "selectAnAction.cpp"

void Peon::preDraw()
{
    this->isAddOnDraw = false;
    if (!this->isActive)
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
        if (!this->isGetMyCell)
        {
            this->goWayAnimation();
        }
        else if (this->inFight)
        {
            if (this->inFightTimer >= 50)
            {
                this->animY = 900;
            }
            else if (this->inFightTimer > 40)
            {
                this->animY = 800;
            }
            else if (this->inFightTimer > 30)
            {
                this->animY = 700;
            }
            else if (this->inFightTimer > 20)
            {
                this->animY = 600;
            }
            else if (this->inFightTimer > 0)
            {
                this->animY = 500;
            }
        }
    }
};