#include "Cell.cpp"

void Cell::draw(int offsetX, int offsetY)
{

  //  console.log("draw cell");
   // int offsetX = gf->drawOffsetX;
    ctx.FillRect(
    this->x - offsetX, 
    this->y - offsetY, 
    this->gabX, 
    this->gabY, 
    this->getMapColor().R,
    this->getMapColor().G,
    this->getMapColor().B,
    255
    );

        ctx.StrokeRect(
    this->x - offsetX, 
    this->y - offsetY, 
    this->gabX, 
    this->gabY, 
    "yellow"
    );
}