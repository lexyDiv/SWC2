#include "controller.cpp"

void Fraction::activeUnitsControl()
{
    for (int i = 0; i < this->activeUnits.length; i++)
    {
        ProtoObj *unit = this->activeUnits.getItem(i);
        if (unit->enemys.length ||
            unit->potentialWay.length ||
            !unit->isPotentialWayComplite ||
            (unit->orderOnWay && !unit->orderOnWay->isComplite) ||
            !unit->isGetMyCell) 
        {
            unit->activeProg();
        }
        else
        {
           // console.log("active delete");
            unit->isActive = false;
            this->activeUnits.splice(i, 1);
            i--;
        }
    }
//console.log(to_string(this->activeUnits.length));
    // this->activeUnits.forEach([](ProtoObj *unit)
    //                           { unit->activeProg(); });

    // this->activeUnits.filterSelf([](ProtoObj *unit)
    //                              {
    //                                  if (!unit->enemys.length ||
    //                                      unit->potentialWay.length ||
    //                                      !unit->isPotentialWayComplite ||
    //                                      unit->orderOnWay)
    //                                  {
    //                                      return false;
    //                                  }
    //                                  return true;
    //                              });
}