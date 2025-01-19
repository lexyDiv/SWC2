#include "getCellImageCellDrawIndexCellUnitInit.cpp"

void GameField::getToTreeCellLineNumber()
{

    this->field.forEach([this](Array<ProtoObj *> line){
        line.forEach([this](ProtoObj* cell){
               this->getVectorCells(cell);
        });
    });

    this->planes.forEach([this](ProtoPlane *plane)
                         {
                           
                             if (plane->type == "ground")
                             {

                                 Array<ProtoObj *> arr;
                                 Array<ProtoObj *> arrAroundDarck;
                                Array<ProtoObj *> arrStones;
                                Array<ProtoObj *> shahts;
                                 
                                 plane->cells.forEach([plane, &arr, &arrStones, &arrAroundDarck, &shahts](ProtoObj *cell)
                                                      {                                 
                if (cell->litera == 't') {
                    ProtoObj *tree = new Tree;
                    tree->create(cell);
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
               if (cell->litera == 'S') {
                    shahts.push(cell);
               }
                                   if (cell->litera == 'g') {
                        arrStones.push(cell);
                        ProtoObj *mount = new Mount();
                        mount->create(cell);
                    }
                    if (cell->litera == 'e') {
                        cell->lineToDarckGround = 1;
                         arrAroundDarck.push(cell);
                    }  
               });
                    arr.forEach([](ProtoObj *firstCell)
                    {
                        
                         firstCell->aroundCells.forEach([](ProtoObj *secondCell)
                                                                              {
                    if (secondCell->litera != 't' && 
                    !secondCell->lineToTreeNumber) {
                        int rand = intRand(0, 5);
                        if (!rand) {secondCell->lineToTreeNumber = 2;}
                    } }); });


                    arrAroundDarck.forEach([](ProtoObj* cell){
                        cell->maxAroundCells.forEach([cell](ProtoObj* ac, int i){
                            int dis = cell->maxAroundCellsDis.getItem(i);
                           if (dis <= 150 && (!ac->lineToDarckGround || (
                            ac->lineToDarckGround > 1
                           ))) {
                                  ac->lineToDarckGround = 1;
                           } else if (dis <= 250 && (!ac->lineToDarckGround || (
                            ac->lineToDarckGround > 2
                           ))) {
                            ac->lineToDarckGround = 2;
                           }
                        });
                    });

                    arrStones.forEach([](ProtoObj* as){
                        as->maxAroundCells.forEach([as](ProtoObj* ac){
                        Delta delta = getDeltas(
                        {as->x + as->gabX, as->y + as->gabY},
                        {ac->x + as->gabX / 2, ac->y + as->gabY /2}
                        ); 
                        double dis = getDis(delta); 
                        if (dis <= 100) {
                            ac->LineToMountNumber = 1;
                        } else if (dis <= 200 && !ac->LineToMountNumber) {
                            ac->LineToMountNumber = 2;
                        }
                        });
                    });

            shahts.forEach([this](ProtoObj *cell, int i){
                ProtoObj *shaht = new Shaht;
                shaht->create(cell);
                shaht->gold = stoi(this->goldData.getItem(i));
            });

            

                             } });
};