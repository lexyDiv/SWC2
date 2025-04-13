#include "../fraction/orderControl.cpp"

void Deleter::process()
{

    for (int i = 0; i < this->orders.length; i++)
    {
        Order *order = this->orders.getItem(i);
        if (order->deleteTimer)
        {
              order->deleteTimer++;
             if (order->deleteTimer == 10)
             {
                delete order;
                order = nullptr;
                this->orders.splice(i, 1);
                i--;
            }
        }
    }
};
