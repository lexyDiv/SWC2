#include "getPotentialWayTarget.cpp"

void Peon::draw() {
    this->preDraw();
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;
    ctx.DrawImage(
    this->image, 
    this->animX, 
    this->animY, 
    this->animGabX, 
    this->animGabY, 
    this->x + drawDeltaX - 25, 
    this->y + drawDeltaY - 25, 
    100, 
    100);
};