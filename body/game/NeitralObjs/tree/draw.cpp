#include "Tree.cpp"

void Tree::draw()
{
  this->isAddOnDraw = false;
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;
  if (this->hp > 0)
  {
    //  ctx.FillRect(this->x + drawDeltaX, this->y + drawDeltaY, 5, 5, "blue");

    ctx.DrawImage(this->image,
                  this->animX, this->animY,
                  this->animGabX, this->animGabY,
                  this->x + drawDeltaX, this->y + drawDeltaY,
                  this->drawGabaritX, this->drawGabaritY);
  }

  this->animTakt++;

  if (this->animTakt == 15)
  {
    this->animX += this->animStepX;
    this->animTakt = 0;
    if (this->animX == 800)
    {
      this->animX = 0;
    }

  }
  // ProtoObj *cell = this->myCells.getItem(0);
  // ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
}