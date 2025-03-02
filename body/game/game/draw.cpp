#include "fonMenuDraw.cpp"

void Game::draw()
{
    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");


        ctx.CreateDrawZone(this->gf->x, this->gf->y, this->gf->screenWidth, this->gf->screenHeight);

        if (this->gf->drawCell != nullptr)
        {
            float drawDeltaX = this->gf->drawDeltaX;
            float drawDeltaY = this->gf->drawDeltaY;

           Array<Array<ProtoObj *>> DA;
           for (int i = 0; i < 130; i++) {
            Array<ProtoObj *> a;
            DA.push(a);
           };

           Array<int> max;
           

            this->gf->drawCell->cellsOnDraw.forEach([drawDeltaY, &DA, &max](Array<ProtoObj *> drawLine){
                drawLine.forEach([drawDeltaY, &DA, &max](ProtoObj* cell){
                    cell->draw();
                    if (cell->groundUnit && !cell->groundUnit->isAddOnDraw) {
                    int index = ceil((((cell->groundUnit->drawIndexY) + drawDeltaY) / 10) + 30);
                        cell->groundUnit->isAddOnDraw = true;
                       Array<ProtoObj *> &line = DA.getItem3(index);                    
                        line.push(cell->groundUnit);
                       max.push(index);
                    }
                });
            });
            
        //    if (max.length) {
        //               max.sort([](int a, int b){
        //         return a > b;
        //     });
        //     int mx = max.getItem(0);
        //     int mn = max.getItem(max.length - 1);
        //     console.log(to_string(mx));
        //    }

            DA.forEach([](Array<ProtoObj * > line){
                line.forEach([](ProtoObj* unit){
                    unit->draw();
                });
            });

            //             this->gf->drawCell->cellsOnDraw.forEach([drawDeltaX, drawDeltaY](Array<ProtoObj *> drawLine){
            //     drawLine.forEach([drawDeltaX, drawDeltaY](ProtoObj* cell){
            //         string color = cell->groundUnit ? "red" : "yellow";
            //         ctx.StrokeRect(
            //                                             cell->x + drawDeltaX,
            //                                             cell->y + drawDeltaY,
            //                                             cell->gabX,
            //                                             cell->gabY,
            //                                             color);
            //     });
            // });
        // this->gf->drawCell->cellsOnDraw.forEach([drawDeltaX, drawDeltaY](Array<ProtoObj* > drawLine){
        //     drawLine.forEach([drawDeltaX, drawDeltaY](ProtoObj* cell){
        //         ctx.StrokeRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY, "yellow");
        //     });
        // });

        if (this->objMenu->unit) {
            ProtoObj* unit = this->objMenu->unit;
   ctx.FillRect(unit->x + drawDeltaX, unit->y + drawDeltaY, unit->gabX, unit->gabY, "red");
        };

        this->objMenu->units.forEach([drawDeltaX, drawDeltaY](ProtoObj* unit){
        ctx.FillRect(unit->x + drawDeltaX, unit->y + drawDeltaY, unit->gabX, unit->gabY, "red");
        });

        /////////////// zone
        FieldClick* fcp = this->gf->fieldClickPoint;
        if (fcp) {
          ctx.StrokeRect(
            fcp->firstX + drawDeltaX, 
            fcp->firstY + drawDeltaY, 
            fcp->gabX, fcp->gabY, "red");
        }
 
      //  console.log(to_string(this->objMenu->candidateCells.length));
        // this->objMenu->candidateCells.forEach([drawDeltaX, drawDeltaY](ProtoObj* cell){
        //     ctx.FillRect(cell->x + drawDeltaX, cell->y + drawDeltaY, cell->gabX, cell->gabY, "red");
        // });
        /////////////// zone

        }

        //  ctx.FillRect(this->gf->centerX, this->gf->centerY + this->gf->y, 3, 3, "black");




        ctx.CreateDrawZone(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight);
        ctx.FillRect(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight, "black");



        ctx.CreateDrawZone(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT);
        ctx.FillRect(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT, "black");

          this->fonMenuDraw();
        this->gf->miniMapDraw();
      if (this->objMenu->unit) {
         this->objMenu->draw();
      }
    //   string s = "Papa Loh";
    //   string s2 = "War Craft 2";
    //   string s3 = "Wee UPSET!";
    //   menuText.draw(s, 730, 400, 20);
    //   menuText.draw(s2, 730, 422, 20);
    //   menuText.draw(s3, 730, 445, 30);
    

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
}
