#include "Mount.cpp"

void Mount::draw() {

  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;

    this->isAddOnDraw = false;
    ctx.DrawImage(this->image,
    this->animX, this->animY,
    this->animGabX, this->animGabY,
    (this->x + drawDeltaX) - 50, (this->y + drawDeltaY) - 65,
    100, 115);

    // this->myCells.forEach([drawDeltaX, drawDeltaY](ProtoObj* cell){
    //     ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY, "red");
    // });
};