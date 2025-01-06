#include "GameField.cpp"

Image *groundBasic = new Image("images/grunt/summer/basick.png");

void GameField::getCellImageCellDrawIndexCellUnitInit()
{
    this->field.forEach([](Array<ProtoObj *> line)
                        { line.forEach([](ProtoObj *cell)
                                       {
            if (
                cell->litera == '0' 
            && !cell->lineToTreeNumber 
            && !cell->lineToOtherPlaneNumber
            && !cell->LineToMountNumber ) {
                cell->cellImage = groundBasic;
                cell->animX = 100 * intRand(0, 30);
                cell->animY = 0;
                cell->animGabX = 100;
                cell->animGabY = 100;
            } }); });
}