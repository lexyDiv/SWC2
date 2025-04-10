#include "controller.cpp"

void Fraction::activeUnitsControl()
{

    this->activeUnits.forEach([](ProtoObj *unit)
                              { unit->activeProg(); });

    this->activeUnits.filterSelf([](ProtoObj *unit)
                                 {
                                     if (!unit->enemys.length ||
                                         unit->potentialWay.length ||
                                         !unit->isPotentialWayComplite ||
                                         unit->orderOnWay)
                                     {
                                         return false;
                                     }
                                     return true;
                                     // if (!unit->enemys.length &&
                                     // (!unit->potentialWay.length && unit->isPotentialWayComplite)) {
                                     //     unit->isActive = false;
                                     //     return true;
                                     // }
                                     // return false;
                                 });
}