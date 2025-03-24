#include "Deleter.cpp"

void Deleter::process()
{
    this->orders.forEach([](Order *order)
                         {
        if (order->deleteTimer) {
            order->deleteTimer ++;
            if (order->deleteTimer == 10) {
                delete order;
                order = nullptr;
            }
        } });

    this->orders.filterSelf([](Order *order)
                            {
            if (!order || !order->deleteTimer) {
                return true;
            }
            return false; });
};

Deleter deleter;