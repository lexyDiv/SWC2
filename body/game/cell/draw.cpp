#include "Cell.cpp"

void Cell::draw()
{

    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    ctx.FillRect(
        this->x + drawDeltaX,
        this->y + drawDeltaY,
        this->gabX,
        this->gabY,
        this->getMapColor().R,
        this->getMapColor().G,
        this->getMapColor().B,
        255);

    ctx.StrokeRect(
        this->x + drawDeltaX,
        this->y + drawDeltaY,
        this->gabX,
        this->gabY,
        "yellow");

       string str = "V= " + to_string((int)this->ver);
       ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 5, 10,  str, 255);
       str = "H= " + to_string((int)this->hor);
       ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 25, 10,  str, 255);
}