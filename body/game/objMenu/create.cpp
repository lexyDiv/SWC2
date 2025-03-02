#include "getCandidateCells.cpp"

void ObjMenu::create(ProtoGameField *gf)
{
  this->gf = gf;
  this->gabX = ctx.SCREEN_WIDTH - this->gf->screenWidth;
  this->mX = ctx.SCREEN_WIDTH - this->gabX;
  this->centerX = this->mX + this->gabX / 2;
  this->buttonsBar.create(this);
};