#include "create.cpp"

void TownHall::draw()
{
    // console.log("draw");
    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    this->myCells.forEach([drawDeltaX, drawDeltaY](ProtoObj *cell)
                          { ctx.StrokeRect(
                          cell->x + drawDeltaX, 
                          cell->y + drawDeltaY, 
                          cell->gabX, 
                          cell->gabY, 
                          "violet"); });
    ctx.DrawImage(this->image,
    0, 0,
    100, 100,
    (this->cell->x - 80) + drawDeltaX,
    (this->cell->y - 100) + drawDeltaY,
    250, 270 
    );                      
    //  ctx.FillRect(this->cell->x + drawDeltaX, this->cell->y + drawDeltaY, this->cell->gabX, this->cell->gabY, "blue");                    
};