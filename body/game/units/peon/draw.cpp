#include "getBaseForUnloading.cpp"

void Peon::draw()
{
  //  this->enemys.forEach([](UnitPack up)
  //                     { console.log(up.unit->name); });
  //    if (this->enemys.length) {
  //                            UnitPack up = this->enemys.pop2();
  //                    console.log("deleted " + up.unit->name);
  //    }
  this->preDraw();
  float drawDeltaX = this->gf->drawDeltaX;
  float drawDeltaY = this->gf->drawDeltaY;

  // if (this->targetCell)
  // {
  //   ctx.FillRect(this->targetCell->x + drawDeltaX,
  //                this->targetCell->y + drawDeltaY, 40, 40, "red");
  // }

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