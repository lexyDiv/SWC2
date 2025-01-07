#include "GameField.cpp"


void GameField::getCellImageCellDrawIndexCellUnitInit()
{
    this->field.forEach([](Array<ProtoObj *> line)
                        { line.forEach([](ProtoObj *cell)
                                       {
            if (
                cell->litera == '0' 
            && !cell->lineToTreeNumber 
            && !cell->lineToOtherPlaneNumber
            && !cell->LineToMountNumber 
            && !cell->lineToDarckGround) {
                
                int rnd = intRand(0, 2);
                Image *img = !rnd ? groundBasic : groundBasic1;

                cell->cellImage = img;
                cell->animX = 100 * intRand(0, 30);
                cell->animY = 0;
                cell->animGabX = 100;
                cell->animGabY = 100;
            } 
            
            if (cell->lineToDarckGround == 1) {
                cell->cellImage = groundBasicDarck;
                cell->animX = 100 * intRand(0, 30);
                cell->animY = 0;
                cell->animGabX = 100;
                cell->animGabY = 100;
            } else if (cell->lineToDarckGround == 2) {
                cell->cellImage = groundBasicDarck1;
                cell->animX = 100 * intRand(0, 30);
                cell->animY = 0;
                cell->animGabX = 100;
                cell->animGabY = 100;
            } 

            if (cell->litera == 't') {
                cell->cellImage = underWood;
                cell->animX = 100 * intRand(0, 60);
                cell->animY = 0;
                cell->animGabX = 100;
                cell->animGabY = 100;
            }

                if (cell->lineToTreeNumber == 1) {
                cell->cellImage = aroundWood1;
                cell->animX = 100 * intRand(0, 30);
                cell->animY = 0;
                cell->animGabX = 100;
                cell->animGabY = 100;
            } else if (cell->lineToTreeNumber == 2) {
                cell->cellImage = aroundWood2;
                cell->animX = 100 * intRand(0, 30);
                cell->animY = 0;
                cell->animGabX = 100;
                cell->animGabY = 100;
            } 

            if (cell->litera == 'w') {
                cell->cellImage = ocean;
                Water *water1 = new Water;
                Water *water2 = new Water;
                water1->alpha = 0;
                cell->waters.push(water1);
                cell->waters.push(water2);
                // cell->animX = 100 * intRand(0, 8);
                // cell->animY = cell->lineToOtherPlaneNumber ? 100 : 0;
                // cell->animGabX = 100;
                // cell->animGabY = 100;
            }

            }); });
}