#include "controller.cpp"

void Fraction::activeUnitsControl()
{
    for (int i = 0; i < this->activeUnits.length; i++)
    {
        ProtoObj *unit = this->activeUnits.getItem(i);
        if (unit &&
            unit->cell &&
            (unit->enemys.length ||
             unit->potentialWay.length ||
             !unit->isPotentialWayComplite ||
             (unit->orderOnWay && !unit->orderOnWay->isComplite) ||
             !unit->isGetMyCell ||
             unit->inFight ||
             unit->outHoldTimer))
        {
            unit->activeProg();
        }
        else
        {
            this->activeUnits.getItem3(i) = nullptr;
            unit->isActive = false;
            // this->activeUnits.splice(i, 1);
            // i--;
        }
    }
    this->activeUnits.filterSelf([](ProtoObj *unit)
                                 { return !unit; });
                             //    console.log(to_string(this->activeUnits.length));
}