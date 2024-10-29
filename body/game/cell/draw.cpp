#include "Cell.cpp"

void Cell::draw(int offsetX, int offsetY)
{
    ctx.StrokeRect(this->x + offsetX, this->y + offsetY, this->gabX, this->gabY, "violet");
}