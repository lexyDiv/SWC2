#include "fractionsControl.cpp"

void Game::getPotentialWayControl()
{
    // console.log(to_string(this->unitsOnWay.length));
    if (this->unitsOnWay.length)
    {
        this->unitsOnWay.forEach([this](ProtoObj *unit)
                                 { 
                                    if (!unit->isPotentialWayComplite) {
                                        this->gf->getPotentialWay(unit);
                                    } });
        this->unitsOnWay.filterSelf([](ProtoObj *unit)
                                    { return unit->isPotentialWayComplite; });
    }
};