#include "controller.cpp"

void Fraction::activeUnitsControl()
{

    this->activeBuildings.forEach([](ProtoObj *building)
                                  { building->activeProg(); });
    this->activeBuildings.filterSelf([](ProtoObj *building)
                                     {
        if (!building->clients.length &&   // pers function will here
        !building->potentialClients.length &&
        !building->outClients.length &&
        building->isComplite &&
        building->hp == building->hpMax &&
        !building->createTimer &&
        !building->updateTimer) {
            building->isActive = false;
            return true;
        }
        return false; });

    for (int i = 0; i < this->activeUnits.length; i++)
    {
        ProtoObj *unit = this->activeUnits.getItem(i);
        if (unit && // pers function will here
            unit->cell &&
            (//unit->enemys.length ||
             unit->potentialWay.length ||
             !unit->isPotentialWayComplite ||
             (unit->orderOnWay && !unit->orderOnWay->isComplite) ||
             !unit->isGetMyCell ||
             unit->inFight ||
             unit->outHoldTimer ||
             unit->pw.length))
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
     //   console.log(to_string(this->activeUnits.length));
}