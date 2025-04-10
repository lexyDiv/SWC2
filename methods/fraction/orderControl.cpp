#include "create.cpp"

void Fraction::orderControl()
{

    for (int i = 0; i < this->orders.length; i++)
    {
        Order *order = this->orders.getItem(i);
        if (order->isComplite)
        {
            ProtoObj *unit = order->unit;
            ProtoObj *cell = order->cell;
            if (unit)
            {
                 unit->getHandTarget(cell);
            }
            order->deleteTimer = 1;
            deleter.orders.push(order);
            this->orders.splice(i, 1);
            i--;
        }
    };

};
