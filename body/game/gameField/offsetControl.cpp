#include "miniMapDraw.cpp"

void GameField::offsetControl()
{
    int mx = mouse.x;
    int my = mouse.y;
    int maxOffsetX = this->width - this->centerX * 2;
    int maxOffsetY = (this->height - this->centerY * 2);
  //  console.log( "this->width : " + to_string(this->width) + " maxOffsetX : " + to_string(maxOffsetX));
    if (mx <= 0 && this->offsetX > 0)
    {
        this->offsetX -= this->offsetStep;
    }
    else if (mx >= ctx.SCREEN_WIDTH - 1)
    {
        this->offsetX += this->offsetStep;
    }
    if (my <= 0)
    {
        this->offsetY -= this->offsetStep;
    }
    else if (my >= ctx.SCREEN_HEIGHT - 1)
    {
        this->offsetY += this->offsetStep;
    }

    //////////////////////////////////////////

   // console.log("offsetX : " + to_string(this->offsetX));

    if (this->offsetX < 0)
    {
        this->offsetX = 0;
    }
    if (this->offsetX > maxOffsetX)
    {
        this->offsetX = maxOffsetX;
    }
/////////////////////////////////////////
    if (this->offsetY < 0)
    {
        this->offsetY = 0;
    }
    if (this->offsetY > maxOffsetY)
    {
        this->offsetY = maxOffsetY;
    }

   this->drawOffsetX = this->x + this->offsetX + this->centerX;
   this->drawOffsetY = this->y + this->offsetY + this->centerY;

    int offsetIndexX = (this->drawOffsetX) / this->cellSize;
    int offsetIndexY = (this->drawOffsetY - this->y) / this->cellSize;

//console.log("ox :" + to_string(this->offsetX) + " oy : " + to_string(this->offsetY));
//console.log("Dox :" + to_string(this->drawOffsetX) + " Doy : " + to_string(this->drawOffsetY));

   // console.log(to_string(offsetIndexX));
    this->drawCell = this->field.getItem(offsetIndexY).getItem(offsetIndexX);
 // console.log("offsetIndexX : " + to_string(offsetIndexX) + " offsetIndexY : " + to_string(offsetIndexY));
}