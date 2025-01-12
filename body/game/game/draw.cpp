#include "Game.cpp"

void Game::draw()
{
    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

    if (this->gf && this->gf->init)
    {
        ctx.CreateDrawZone(this->gf->x, this->gf->y, this->gf->screenWidth, this->gf->screenHeight);

        if (this->gf->drawCell != nullptr)
        {
            float drawDeltaX = this->gf->drawDeltaX;
            float drawDeltaY = this->gf->drawDeltaY;

            // this->gf->drawCell->drawCells.forEach([](ProtoObj *cell)
            //                                       { cell->draw(); });
           
           // console.log(to_string(this->gf->drawCell->cellsOnDraw.getItem(0).length));
           Array<ProtoObj *> unitsOnDraw;

            this->gf->drawCell->cellsOnDraw.forEach([&unitsOnDraw](Array<ProtoObj *> drawLine){
                drawLine.forEach([&unitsOnDraw](ProtoObj* cell){
                  //  console.log("here");
                    cell->draw();
                    if (cell->groundUnit && !cell->groundUnit->isAddOnDraw) {
                        cell->groundUnit->isAddOnDraw = true;
                        unitsOnDraw.push(cell->groundUnit);
                    }
                });
            });

            unitsOnDraw.sort([](ProtoObj* a, ProtoObj* b){
                return a->y < b->y;
            });

            unitsOnDraw.forEach([](ProtoObj *unit){
                unit->draw();
            });

            // this->gf->drawCell->drawCells.forEach([drawDeltaX, drawDeltaY](ProtoObj *cell)
            //                                       { ctx.StrokeRect(
            //                                             cell->x + drawDeltaX,
            //                                             cell->y + drawDeltaY,
            //                                             cell->gabX,
            //                                             cell->gabY,
            //                                             "yellow"); });
        }

        //  ctx.FillRect(this->gf->centerX, this->gf->centerY + this->gf->y, 3, 3, "black");

        ctx.CreateDrawZone(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight);
        ctx.FillRect(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight, "black");

        ctx.CreateDrawZone(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT);
        ctx.FillRect(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT, "black");

        this->gf->miniMapDraw();
    }

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
}
