#include "orderOnWayControl.cpp"

void GroundUnit::goWayAnimation()
{
    this->animTimer++;
    if (this->animTimer == 100)
    {
        this->animTimer = 1;
    }
    if (this->animTimer % 8 == 0)
    {
        this->animY += this->animGabY;
        if (this->animY == this->animGabY * 5)
        {
            this->animY = this->animGabY;
        }
    }
};