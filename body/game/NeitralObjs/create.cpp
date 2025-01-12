#include "draw.cpp"

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

    this->animX = 200 * intRand(0, 5);

    int rand = intRand(0, 3);
    this->image = !rand ? gora1 : rand == 1 ? gora4 : gora3;
    this->animGabX = 200;
    this->animGabY = 200;
    this->gf = cell->gf;

    this->name = "mount";

}