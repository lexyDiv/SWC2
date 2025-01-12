#include "Tree.cpp"

void Tree::draw()
{
  this->isAddOnDraw = false;
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;  
    if (this->hp > 0)
    {

        ctx.DrawImage(this->image,
                      this->animX, this->animY,
                      this->animGabX, this->animGabY,
                      this->x + drawDeltaX, this->y + drawDeltaY,
                      this->drawGabaritX, this->drawGabaritY);
    }
    // ProtoObj *cell = this->myCells.getItem(0);
    // ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
}