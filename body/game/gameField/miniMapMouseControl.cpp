#include "offsetControl.cpp"

void GameField::miniMapMouseControl()
{
    bool click = mouse.leftKeyDown;
    if (mouse.leftKeyUp)
    {
        this->miniMapClick = false;
    }
    if (click)
    {
        int mx = mouse.x;
        int my = mouse.y;

        if (!(mx < this->miniMapX || mx > this->miniMapX + this->miniMapGab ||
              my < this->miniMapY || my > this->miniMapY + this->miniMapGab))
        {
            // console.log(to_string(mouse.leftKeyDown));
            this->miniMapClick = true;
            this->miniMapClickX = mx;
            this->miniMapClickY = my;
        }
    }

    if (this->miniMapClick)
    {
        
    }
}