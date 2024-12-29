#include "Cell.cpp"

void Cell::draw()
{

    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;

    ctx.FillRect(
        this->x + drawDeltaX,
        this->y + drawDeltaY,
        this->gabX,
        this->gabY,
        this->getMapColor().R,
        this->getMapColor().G,
        this->getMapColor().B,
        255);

    ctx.StrokeRect(
        this->x + drawDeltaX,
        this->y + drawDeltaY,
        this->gabX,
        this->gabY,
        "yellow");


      if (this->plane) {
    //     string str = "K: " + to_string(this->plane->number);
    //     if (this->plane->type == "sea") {
    //       str = "S: " + to_string(this->plane->number);
    //     }
    //    ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 5, 10,  str, 255);
    // if (this->lineToOtherPlaneNumber && this->plane->type == "ground") {
    //           ctx.StrokeRect(
    //     this->x + drawDeltaX,
    //     this->y + drawDeltaY,
    //     this->gabX,
    //     this->gabY,
    //     "red");
    // }
    //   if (this->plane->type == "sea" && this->lineToOtherPlaneNumber) {
    //         string str = "K: " + to_string(this->lineToOtherPlaneNumber);
    //        ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 5, 10,  str, 255);
    //   }
          if (this->plane->type == "ground" && this->LineToMountNumber) {
            string str = "K: " + to_string(this->LineToMountNumber);
           ctx.DrawText(this->x + drawDeltaX, this->y + drawDeltaY + 5, 10,  str, 255);
      }
      }

}