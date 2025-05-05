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
            int indexY = ceil((y - drawDeltaY - this->y) / cellSize);

            unit->orderOnWay = unit->orderOnWay ? unit->orderOnWay : new Order;
            ProtoObj *cell = this->field.getItem(indexY).getItem(indexX);
            unit->orderOnWay->cell = cell;
            unit->orderOnWay->isComplite = false;

            // console.log("order");
            if (!unit->isActive)
            {
                // console.log("push active");
                unit->isActive = true;
                unit->fraction->activeUnits.push(unit);
            }
        }
    }
};