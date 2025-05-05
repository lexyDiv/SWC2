#include "isNextCellFreeToGoWay.cpp"

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
};