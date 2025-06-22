#include "isTargetObjValide.cpp"

void GroundUnit::inFightAnimation()
{
    if (this->inFightTimer >= 50)
    {
        this->animY = 900;
    }
    else if (this->inFightTimer > 45)
    {
        this->animY = 800;
    }
    else if (this->inFightTimer > 40)
    {
        this->animY = 700;
    }
    else if (this->inFightTimer > 8)
    {
        this->animY = 600;
    }
    else if (this->inFightTimer > 0)
    {
        this->animY = 500;
    }
};