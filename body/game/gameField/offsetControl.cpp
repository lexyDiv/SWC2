#include "miniMapDraw.cpp"

void GameField::offsetControl()
{
    int mx = mouse.x;
    int my = mouse.y;
    int maxOffsetX = this->width - this->centerX;
    int maxOffsetY = (this->height - this->centerY);
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

   this->drawOffsetX = this->x + this->offsetX;
   this->drawOffsetY = this->y + this->offsetY;

    int offsetIndexX = (this->drawOffsetX + this->centerX) / this->cellSize;
    int offsetIndexY = (this->drawOffsetY + this->centerY) / this->cellSize;

   // console.log(to_string(offsetIndexX));
    this->drawCell = this->field.getItem(offsetIndexY).getItem(offsetIndexX);
   // console.log(to_string(this->drawCell->x));
   // console.log(to_string(this->offsetY));
    // console.log("mouse.x = " + to_string(mouse.x) + "screen.width = " + to_string(ctx.SCREEN_WIDTH));
}