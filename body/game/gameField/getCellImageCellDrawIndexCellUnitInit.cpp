#include "GameField.cpp"

Image *groundBasic = new Image("images/grunt/summer/basic/basick.png");
Image *groundBasic1 = new Image("images/grunt/summer/basick.png");
Image *groundBasicDarck1 = new Image("images/grunt/summer/basick_tem1.png");
Image *groundBasicDarck = new Image("images/grunt/summer/basick_tem.png");

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

            }); });
}