#include "getVectorCells.cpp"

void GameField::fieldClickRight()
{
    ProtoObj *unit = this->game->objMenu->unit;
    if (unit &&
        unit->fraction &&
        unit->type == "life")
    {
        bool clickRight = mouse.rightKeyDown;
        float drawDeltaX = this->drawDeltaX;
        float drawDeltaY = this->drawDeltaY;
        int x = mouse.x;
        int y = mouse.y;

        bool inField = bool(x < this->x + this->screenWidth &&
                            y > this->y && y < this->y + this->screenHeight);

        if (clickRight && inField)
        {
            int indexX = ceil((x - drawDeltaX) / cellSize) - 1;
            //    // console.log("index x = " + to_string(indexX));
            int indexY = ceil((y - drawDeltaY - this->y) / cellSize);
            //     ProtoObj *cell = this->field.getItem(indexY).getItem(indexX);
            //     Order *order = new Order;
            //     order->unit = unit;
            //     order->cell = cell;
            //     unit->fraction->orders.push(order);
            //     order->isComplite = true;

            Order *order = new Order;
            ProtoObj *cell = this->field.getItem(indexY).getItem(indexX);
            order->cell = cell;
            if (unit->orderOnWay)
            {
                deleter.orders.push(unit->orderOnWay);
            }
            unit->orderOnWay = order;
            if (!unit->isActive)
            {
                unit->isActive = true;
                unit->fraction->activeUnits.push(unit);
            }
        }
    }
};