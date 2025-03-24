#include "create.cpp"

void Fraction::orderControl()
{
    this->orders.forEach([this](Order *order)
                         {
        if (order->isComplite) {
            ProtoObj *unit = order->unit;
            ProtoObj *cell = order->cell;
            if (unit) {
                unit->getHandTarget(cell);     
            }
            order->deleteTimer = 1;
            deleter.orders.push(order);
        } });

    this->orders.filterSelf([](Order *order)
                            { return bool(order->deleteTimer); });
};