#include "offsetControl.cpp"

void GameField::miniMapMouseControl()
{
    int mx = mouse.x;
    int my = mouse.y;

    bool click = mouse.leftKeyDown;
    if (mouse.leftKeyUp)
    {
        this->miniMapClick = false;
    }
    if (click)
    {
        if (!(mx < this->miniMapX || mx > this->miniMapX + this->miniMapGab ||
              my < this->miniMapY || my > this->miniMapY + this->miniMapGab))
        {
            this->miniMapClick = true;
            this->miniMapClickX = mx;
            this->miniMapClickY = my;

            int clickIndexX, clickIndexY;
            clickIndexX = (this->miniMapClickX - this->miniMapX) / this->mcs;
            clickIndexY = (this->miniMapClickY - this->miniMapY) / this->mcs;
            ProtoObj *cell = this->field.getItem(clickIndexY).getItem(clickIndexX);
            int deltaIndexX = this->drawCell->hor - cell->hor;
            int deltaIndexY = this->drawCell->ver - cell->ver;
            int deltaScrollX = deltaIndexX * this->cellSize;
            int deltaScrollY = deltaIndexY * this->cellSize;
            this->offsetX -= deltaScrollX;
            this->offsetY -= deltaScrollY;
            this->offsetControl();
        }
    }

    if (this->miniMapClick)
    {

        float drawCellX = this->drawCell->hor * this->mcs;
        float drawCellY = this->drawCell->ver * this->mcs;

        float deltaX = mouse.x - this->miniMapClickX;
        float deltaY = mouse.y - this->miniMapClickY;

        if (deltaX || deltaY)
        {
            console.log(to_string(deltaX));
           // console.log("here");
            int clickIndexX, clickIndexY;
            int dx = this->miniMapClickX - this->miniMapX;
            int dy = this->miniMapClickY - this->miniMapY;
            dx = dx < 0 ? 0 : dx;
            dx = dx > this->miniMapGab - 1 ? this->miniMapGab - 1 : dx;
            dy = dy < 0 ? 0 : dy;
            dy = dy > this->miniMapGab - 1 ? this->miniMapGab - 1 : dy;
            this->dx = dx;
            this->dy = dy;
            clickIndexX = this->dx / this->mcs;
            clickIndexY = this->dy / this->mcs;
           // console.log(to_string(dx));
            // if (clickIndexX < 0)
            // {
            //     clickIndexX = 0;
            // }
            // else if (clickIndexX > this->gabarit - 1)
            // {
            //     clickIndexX = this->gabarit - 1;
            // }
            // if (clickIndexY < 0)
            // {
            //     clickIndexY = 0;
            // }
            // else if (clickIndexY > this->gabarit - 1)
            // {
            //     clickIndexY = this->gabarit - 1;
            // }
            ProtoObj *cell = this->field.getItem(clickIndexY).getItem(clickIndexX);
            int deltaIndexX = this->drawCell->hor - cell->hor;
            int deltaIndexY = this->drawCell->ver - cell->ver;
            int deltaScrollX = deltaIndexX * this->cellSize;
            int deltaScrollY = deltaIndexY * this->cellSize;
            this->offsetX -= deltaScrollX;
            this->offsetY -= deltaScrollY;
        }

        this->miniMapClickX = mouse.x;
        this->miniMapClickY = mouse.y;
    }
}