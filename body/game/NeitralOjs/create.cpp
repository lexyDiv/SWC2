#include "Mount.cpp"

void Mount::create(ProtoObj *cell)
{
    cell->groundUnit = this;
    this->myCells.push(cell);
    cell->bottom->groundUnit = this;
    this->myCells.push(cell->bottom);
    cell->right->groundUnit = this;
    this->myCells.push(cell->right);
    cell->right->bottom->groundUnit = this;
    this->myCells.push(cell->right->bottom);

    this->x = cell->x + cell->gabX;
    this->y = cell->y + cell->gabY;

    this->image = gora1;
    this->animGabX = 200;
    this->animGabY = 200;

}