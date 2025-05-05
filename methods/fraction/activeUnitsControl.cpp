#include "controller.cpp"

void Fraction::activeUnitsControl()
{
    for (int i = 0; i < this->activeUnits.length; i++)
    {
        ProtoObj *unit = this->activeUnits.getItem(i);
        if (unit &&
            (unit->enemys.length ||
             unit->potentialWay.length ||
             !unit->isPotentialWayComplite ||
             (unit->orderOnWay && !unit->orderOnWay->isComplite) ||
             !unit->isGetMyCell))
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
}