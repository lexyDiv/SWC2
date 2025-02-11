#include "create.cpp"

void Oil::draw()
{
  //  console.log(to_string(this->gf->field.length));
    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;
    ctx.DrawImage(this->image, 
    0, 0, 
    100, 100, 
    this->x + drawDeltaX, this->y + drawDeltaY, 
    this->getGabX, this->getGabY);
    this->myCells.forEach([this, drawDeltaX, drawDeltaY](ProtoObj* cell){
        ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
    });
};