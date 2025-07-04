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

    ///////////////////////////////////////////// <= ok

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

    //  console.log(to_string(this->unitsOnWay.length));

    // while (!needReturn)
    // {
    //     if (this->unitsOnWay.length)
    //     {
    //         ProtoObj *unit = this->unitsOnWay.getItem(0);
    //         if (unit)
    //         {
    //             this->gf->getPotentialWay(unit);
    //         }
    //         if (!unit->isPotentialWayComplite)
    //         {
    //             return;
    //         }

    //         this->unitsOnWay.shift();
    //     }
    // }

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

 int hold2 = 0;

void Game::getPotentialWayControl2()
{

    for (int i = hold2; i < this->allPeons2.length; i++)
    {
        if (needReturn)
        {
           // console.log("hold: " + to_string(hold));
            return;
        }
        hold2 = i;
        ProtoObj *peon = this->allPeons2.getItem(i);
        if (!peon->isPotentialWayComplite)
        {
            this->gf->getPotentialWay2(peon);
            peon->isPotentialWayComplite = true;
        }
    };

      hold2 = 0;

    ///////////////////////////////////////////// <= ok

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

    //  console.log(to_string(this->unitsOnWay.length));

    // while (!needReturn)
    // {
    //     if (this->unitsOnWay.length)
    //     {
    //         ProtoObj *unit = this->unitsOnWay.getItem(0);
    //         if (unit)
    //         {
    //             this->gf->getPotentialWay(unit);
    //         }
    //         if (!unit->isPotentialWayComplite)
    //         {
    //             return;
    //         }

    //         this->unitsOnWay.shift();
    //     }
    // }

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