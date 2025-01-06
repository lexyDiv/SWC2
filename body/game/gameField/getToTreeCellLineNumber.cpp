#include "getCellImageCellDrawIndexCellUnitInit.cpp"

void GameField::getToTreeCellLineNumber()
{

    this->planes.forEach([](ProtoPlane *plane)
                         {
                            Array<ProtoObj *> arrStones;
                             if (plane->type == "ground")
                             {

                                 Array<ProtoObj *> arr;
                                 
                                 
                                 plane->cells.forEach([plane, &arr, &arrStones](ProtoObj *cell)
                                                      {                                 
                if (cell->litera == 't' || cell->litera == '1') {
                    cell->aroundCells.forEach([plane, &arr](ProtoObj* ac){
                        if (ac->plane == plane &&
                        ac->litera != 't' && ac->litera != '1' &&
                        !ac->lineToTreeNumber) {
                            ac->lineToTreeNumber = 1;
                            arr.push(ac);
                        }
                    });
                  plane->treeCells.push(cell);
               } 
                                   if (cell->litera == 'g') {
                        arrStones.push(cell);
                    }  
               });
                                 arr.forEach([](ProtoObj *firstCell)
                                             { firstCell->aroundCells.forEach([](ProtoObj *secondCell)
                                                                              {
                    if (secondCell->litera != 't' && 
                    secondCell->litera != '1' && 
                    !secondCell->lineToTreeNumber) {
                        secondCell->lineToTreeNumber = 2;
                    } }); });

                     Array<ProtoObj*> firstLineToStone;
                    arrStones.forEach([&firstLineToStone](ProtoObj* stoneCell){
                        stoneCell->aroundCells.forEach([&firstLineToStone](ProtoObj * firstLineSC){
                            if (firstLineSC->litera != 'g' && !firstLineSC->LineToMountNumber) {
                                firstLineSC->LineToMountNumber = 1;
                                firstLineToStone.push(firstLineSC);
                            }
                        });
                    });
                    firstLineToStone.forEach([](ProtoObj* sc){
                        sc->aroundCells.forEach([](ProtoObj* ac){
                            if (!ac->LineToMountNumber && ac->litera != 'g') {
                                ac->LineToMountNumber = 2;
                            }
                        });
                    });
                             } });
};