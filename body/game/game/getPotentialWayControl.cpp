#include "fractionsControl.cpp"

void Game::getPotentialWayControl()
{
    if (this->unitsOnWay.length)
    {
       // console.log(to_string(this->unitsOnWay.length));
        for (int i = 0; i < this->unitsOnWay.length; i++)
        {
            ProtoObj *unit = this->unitsOnWay.getItem(i);
            this->gf->getPotentialWay(unit);
            this->unitsOnWay.shift();
            i--;
                }
    }
};