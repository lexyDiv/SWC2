#include "fractionsControl.cpp"

void Game::getPotentialWayControl()
{

    for (int i = hold; i < this->allPeons.length; i++)
    {
        if (needReturn)
        {
           // console.log("hold: " + to_string(hold));
            return;
        }
        hold = i;
        ProtoObj *peon = this->allPeons.getItem(i);
        if (!peon->isPotentialWayComplite)
        {
            this->gf->getPotentialWay(peon);
            peon->isPotentialWayComplite = true;
        }
    };

      hold = 0;
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