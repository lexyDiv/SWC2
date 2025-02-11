#include "create.cpp"

void Oil::draw()
{
    //  console.log(to_string(this->gf->field.length));
    this->isAddOnDraw = false;
    float drawDeltaX = this->gf->drawDeltaX;
    float drawDeltaY = this->gf->drawDeltaY;
   // this->linePullerY += 3;
    this->linePusherY += 2;

    int hold = 20;
    int s = 100 / this->linesCount;
    int index = this->linePusherY / s;
   // this->linePullerY = this->linePullerY >= 100 + hold * s ? -hold * s : this->linePullerY;
    this->linePusherY = this->linePusherY >= 100 + hold * s ? -hold * s : this->linePusherY;

   this->lines.forEach([](AnimLines* line){
    line->deltaX -= 0.03;
   });

    for (int i = index - hold; i < index + hold; i++)
    {
        if (i >= 0 && i < this->lines.length)
        {
            AnimLines *line = this->lines.getItem(i);
            float delta = abs(this->linePusherY - line->y);
            line->deltaX = delta / 20;
        }
    }
    int index2 = this->linePullerY / s;
    // for (int i = index2 - hold; i < index2 + hold; i++)
    // {
    //     if (i >= 0 && i < this->lines.length)
    //     {
    //         AnimLines *line = this->lines.getItem(i);
    //         float delta = abs(this->linePullerY - line->y);
    //         line->deltaX = !line->deltaX ? delta / 20 : 0 ;
    //     }
    // }

    this->lines.forEach([this](AnimLines *line)
                        { line->draw(this); });

            //             this->myCells.forEach([drawDeltaX, drawDeltaY](ProtoObj* cell){                       
            // ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY);
            //             });
};