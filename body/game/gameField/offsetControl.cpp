#include "miniMapDraw.cpp"

void GameField::offsetControl()
{
    int mx = mouse.x;
    int my = mouse.y;
    int maxOffsetX = this->width - this->centerX;
    int maxOffsetY = this->height - this->centerY;
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

    if (this->offsetY < 0)
    {
        this->offsetY = 0;
    }
    if (this->offsetY > maxOffsetY)
    {
        this->offsetY = maxOffsetY;
    }

   // console.log(to_string(this->offsetY));
    // console.log("mouse.x = " + to_string(mouse.x) + "screen.width = " + to_string(ctx.SCREEN_WIDTH));
}