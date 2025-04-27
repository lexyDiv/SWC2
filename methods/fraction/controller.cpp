#include "../buttonData/createOut.cpp"

void Fraction::controller()
{
    if (this->control == "human")
    {
        this->orderControl();
    }
    this->activeUnitsControl();

    /////////////////////// test

    // ProtoObj *one = this->game->gf->field.getItem(10).getItem(2);
    // ProtoObj *too = this->game->gf->field.getItem(10).getItem(16);

    // this->peons.forEach([one, too](ProtoObj *peon)
    //                     {
 
    //  int rand = intRand(0, 10);
    // if (!peon->isActive && !rand) {
    //         peon->orderOnWay = peon->orderOnWay ? peon->orderOnWay : new Order;
    //         ProtoObj *cell = peon->cell->hor < 3 ? too : one;
    //         peon->orderOnWay->cell = cell;
    //         peon->orderOnWay->isComplite = false;

    //         // console.log("order");
    //         if (!peon->isActive)
    //         {
    //             // console.log("push active");
    //             peon->isActive = true;
    //             peon->fraction->activeUnits.push(peon);
    //         }
    // } });
};