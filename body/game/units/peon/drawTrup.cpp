#include "getBaseForUnloading.cpp"

void Peon::drawTrup()
{

    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    ctx.DrawImage(this->image,
                  this->animX, this->animY,
                  this->animGabX, this->animGabY,
                  this->x + drawDeltaX - 25,
                  this->y + drawDeltaY - 25,
                  100, 100, SDL_FLIP_NONE, 0, this->alpha);
};