#include "GameField.cpp"

void GameField::getCellImageCellDrawIndexCellUnitInit()
{

    this->field.forEach([](Array<ProtoObj *> line)
                        {
                            line.forEach([](ProtoObj *cell)
                                         {
                                             if (cell->litera == '0')
                                             {
                                                 if (

                                                     // && !cell->lineToTreeNumber
                                                     !cell->lineToOtherPlaneNumber && !cell->LineToMountNumber
                                                     //  && !cell->lineToDarckGround
                                                 )
                                                 {

                                                     int rnd = intRand(0, 2);
                                                     Image *img = !rnd ? groundBasic : groundBasic1;

                                                     cell->cellImage = img;
                                                     cell->animX = 100 * intRand(0, 30);
                                                     cell->animY = 0;
                                                     cell->animGabX = 100;
                                                     cell->animGabY = 100;
                                                     cell->cellDrawIndex = 2;
                                                 }
                                                 else if (cell->lineToOtherPlaneNumber)
                                                 {
                                                     Image *img = cell->lineToOtherPlaneNumber == 1 ? pesok1 : pesok2;
                                                     cell->cellImage = img;
                                                     cell->animX = 100 * intRand(0, 5);
                                                     cell->animY = 0;
                                                     cell->animGabX = 100;
                                                     cell->animGabY = 100;
                                                     cell->cellDrawIndex = cell->lineToOtherPlaneNumber == 1 ? 1 : 0;
                                                    // cell->drawGabaritX = cell->lineToOtherPlaneNumber == 1 ? 100 : 100;
                                                    // cell->drawGabaritY = cell->drawGabaritX;
                                                 }

                                                 if (cell->LineToMountNumber)
                                                 {
                                                     Image *img = cell->LineToMountNumber == 1 ? mount1 : mount2;
                                                     cell->cellImage = img;
                                                     cell->animX = 100 * intRand(0, 12);
                                                     cell->animY = 0;
                                                     cell->animGabX = 100;
                                                     cell->animGabY = 100;
                                                     cell->cellDrawIndex = 0;
                                                 }
                                             }

                                             if (cell->lineToDarckGround == 1)
                                             {
                                                 cell->cellImage = groundBasicDarck;
                                                 cell->animX = 100 * intRand(0, 30);
                                                 cell->animY = 0;
                                                 cell->animGabX = 100;
                                                 cell->animGabY = 100;
                                                 cell->cellDrawIndex = 3;
                                             }
                                             else if (cell->lineToDarckGround == 2)
                                             {
                                                 cell->cellImage = groundBasicDarck1;
                                                 cell->animX = 100 * intRand(0, 30);
                                                 cell->animY = 0;
                                                 cell->animGabX = 100;
                                                 cell->animGabY = 100;
                                                 cell->cellDrawIndex = 3;
                                             }

                                             if (cell->litera == 't')
                                             {
                                                 cell->cellImage = underWood;
                                                 cell->animX = 100 * intRand(0, 60);
                                                 cell->animY = 0;
                                                 cell->animGabX = 100;
                                                 cell->animGabY = 100;
                                                 cell->cellDrawIndex = 1;
                                             }

                                             if (!cell->lineToOtherPlaneNumber)
                                             {
                                                 if (cell->lineToTreeNumber == 1)
                                                 {
                                                     cell->cellImage = aroundWood1;
                                                     cell->animX = 100 * intRand(0, 30);
                                                     cell->animY = 0;
                                                     cell->animGabX = 100;
                                                     cell->animGabY = 100;
                                                     cell->cellDrawIndex = 3;
                                                 }
                                                 else if (cell->lineToTreeNumber == 2)
                                                 {
                                                     cell->cellImage = aroundWood2;
                                                     cell->animX = 100 * intRand(0, 30);
                                                     cell->animY = 0;
                                                     cell->animGabX = 100;
                                                     cell->animGabY = 100;
                                                     cell->cellDrawIndex = 3;
                                                 }
                                             }

                                             if (cell->litera == 'w')
                                             {
                                                 cell->cellImage = ocean;
                                                 Water *water1 = new Water;
                                                 Water *water2 = new Water;
                                                 int rand = intRand(0, 2);
                                                 water1->alpha = rand ? 250 : 0;
                                                 water2->alpha = rand ? 0 : 250;
                                                 int checkTakt = intRand(1, 3);
                                                 water1->checkTakt = checkTakt;
                                                 water2->checkTakt = checkTakt;
                                                 cell->waters.push(water1);
                                                 cell->waters.push(water2);
                                                 water1->animX = 100 * intRand(0, 8);
                                                 water1->animY = cell->lineToOtherPlaneNumber ? 100 : 0;
                                                 water2->animX = 100 * intRand(0, 8);
                                                 water2->animY = cell->lineToOtherPlaneNumber ? 100 : 0;
                                                 cell->animGabX = 100;
                                                 cell->animGabY = 100;
                                                 cell->cellDrawIndex = 2;
                                             }
                                         });
                        });


            

    this->field.forEach([](Array<ProtoObj *> arr)
                        { arr.forEach([](ProtoObj *cell)
                                      { 

        for (int i = 0; i <= 3; i++) {
            Array<ProtoObj *> arr;
            cell->drawCells.forEach([i, &arr](ProtoObj* dc){
                if (dc->cellDrawIndex == i) {
                    arr.push(dc);
                }
            });
            cell->cellsOnDraw.push(arr);
        }
         
         cell->drawCells.clear();
 
                                      //  console.log(to_string(cell->cellDrawIndex));
                // cell->drawCells.sort([](ProtoObj *a, ProtoObj *b)
                //     { return a->cellDrawIndex < b->cellDrawIndex; }); 
                                                             
                                                             }); });

}