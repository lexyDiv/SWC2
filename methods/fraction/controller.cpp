#include "../buttonData/createOut.cpp"

void Fraction::controller()
{
    if (this->control == "human")
    {
        // this->orderControl();
        this->controlTimer++;
        if (this->controlTimer == 100)
        {
            this->controlTimer = 0;
            this->peons.filterSelf([](ProtoObj *peon)
                                   {
            if (peon) {
                return false;
            }
            return true; });
            int current = 0;
            if (this->hold >= this->peons.length - 1)
            {
                console.log("obnul");
                this->hold = 0;
            }
            console.log("hold: " + to_string(this->hold));
            console.log("length: " + to_string(this->peons.length));
            console.log("-------------------");
            for (int i = this->hold; i < this->peons.length; i++)
            {
               // current++;
                this->hold = i;
                ProtoObj *peon = this->peons.getItem(i);
                if (!peon->inSave &&
                    !peon->isActive &&
                    peon->profession == "w" &&
                    !peon->isBlockedd(peon))
                {
                    current++;
                    ProtoObj *tree = peon->getAnyTree();
                    if (tree)
                    {
                        peon->orderOnWay->isComplite = false;
                        peon->orderOnWay->cell = tree->cell;
                        peon->isActive = true;
                        this->activeUnits.push(peon);
                    }
                }
                if (current == 100)
                {
                    break;
                }
            };
        }
    }
    this->activeUnitsControl();

    /////////////////////// test

    // ProtoObj *one = this->game->gf->field.getItem(10).getItem(3);
    // ProtoObj *too = this->game->gf->field.getItem(10).getItem(6);

    // ProtoObj *one1 = this->game->gf->field.getItem(7).getItem(6);
    // ProtoObj *too1 = this->game->gf->field.getItem(7).getItem(3);

    // this->peons.forEach([one, too, one1, too1](ProtoObj *peon, int i)
    //                     {

    //     if (!i) {
    //              int rand = intRand(0, 10);
    // if (!peon->isActive && !rand) {
    //         peon->orderOnWay = peon->orderOnWay ? peon->orderOnWay : new Order;
    //         ProtoObj *cell = peon->cell == one ? one1 : one;
    //         peon->orderOnWay->cell = cell;
    //         peon->orderOnWay->isComplite = false;

    //        //  console.log("order");
    //         if (!peon->isActive)
    //         {
    //             // console.log("push active");
    //             peon->isActive = true;
    //             peon->fraction->activeUnits.push(peon);
    //         }
    // }
    //     }
    //     else {
    //              int rand = intRand(0, 10);
    // if (!peon->isActive && !rand) {
    //         peon->orderOnWay = peon->orderOnWay ? peon->orderOnWay : new Order;
    //         ProtoObj *cell = peon->cell == too ? too1 : too;
    //         peon->orderOnWay->cell = cell;
    //         peon->orderOnWay->isComplite = false;

    //         // console.log("order");
    //         if (!peon->isActive)
    //         {
    //             // console.log("push active");
    //             peon->isActive = true;
    //             peon->fraction->activeUnits.push(peon);
    //         }
    // }
    //     }

    // });
};