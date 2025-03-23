#include "create.cpp"

void Fraction::orderControl() {
    this->orders.forEach([this](Order* order){
        if (order->isComplite) {
            ProtoObj *unit = order->unit;
            ProtoObj *cell = order->cell;
            if (unit) {
                console.log("here");
                unit->getHandTarget(cell);
                // if (!unit->isActive) {
                //    // this->activeUnits.push(unit);
                //    // unit->handTarget = cell;
                //   //  unit->handTargetTimer = unit->handTargetMaxTime;
                // }
            }
            delete order;
            order = nullptr;
        }
    });
   this->orders.clear();
};