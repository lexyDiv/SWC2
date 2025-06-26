#include "fractionsControl.cpp"

void Game::getPotentialWayControl()
{

    this->allPeons.forEach([this](ProtoObj * peon){
        if (!peon->isPotentialWayComplite) {
            this->gf->getPotentialWay(peon);
            peon->isPotentialWayComplite = true;
        }
    });

    // for (int i = 0; i < this->unitsOnWay.length; i++)
    // {
    //     ProtoObj *unit = this->unitsOnWay.getItem(i);
    //     this->gf->getPotentialWay(unit);
    // }

    //     this->unitsOnWay.filterSelf([](ProtoObj *unit)
    //                             {
    //     if (unit->isPotentialWayComplite) {
    //         return true;
    //     }
    //     return false; });

    // console.log(to_string(this->unitsOnWay.length));

    // while (true)
    // {
    //     // this->unitsOnWay.shift()->
    //     if (!this->unitsOnWay.length)
    //     {
    //         return;
    //     }
    //     this->gf->getPotentialWay(this->unitsOnWay.shift());
    // }

    // if (this->unitsOnWay.length)
    // {
    //    // console.log(to_string(this->unitsOnWay.length));
    //     for (int i = 0; i < this->unitsOnWay.length; i++)
    //     {
    //         ProtoObj *unit = this->unitsOnWay.getItem(i);
    //         this->gf->getPotentialWay(unit);
    //         this->unitsOnWay.shift();
    //         i--;
    //             }
    // }
    // else {
    //     console.log("clear here");
    // }
};