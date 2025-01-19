#include "create.cpp"

void Shaht::draw() {
    this->isAddOnDraw = false;
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;
int animY = !this->clients.length ? 0 : this->animStepY;
   
   ctx.DrawImage(this->image,
   this->animX, animY,
   this->animGabX, this->animGabY,
   this->x + drawDeltaX - 80, this->y + drawDeltaY - 105,
   160, 195);

//    this->myCells.forEach([drawDeltaX, drawDeltaY](ProtoObj *cell){
//     ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
//    });

}