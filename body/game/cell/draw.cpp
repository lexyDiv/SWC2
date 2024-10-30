#include "Cell.cpp"

void Cell::draw()
{

  //  console.log("draw cell");
   // int offsetX = gf->drawOffsetX;
    int offsetX = this->gf->x;
    int offsetY = this->gf->y;

    ctx.FillRect(
    this->x, 
    this->y, 
    this->gabX, 
    this->gabY, 
    this->getMapColor().R,
    this->getMapColor().G,
    this->getMapColor().B,
    255
    );

        ctx.StrokeRect(
    this->x, 
    this->y, 
    this->gabX, 
    this->gabY, 
    "yellow"
    );

    if (this == this->gf->drawCell) {
        ctx.FillRect(    this->x, 
    this->y, 
    this->gabX, 
    this->gabY, 
    "violet");
    console.log("ver : " + to_string(this->ver) + " hor : " + to_string(this->hor));
    }
}