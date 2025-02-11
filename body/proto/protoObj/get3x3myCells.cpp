#include "get2x2myCells.cpp"

void ProtoObj::get3x3myCells(ProtoObj *cell)
{
    cell->groundUnit = this;
    this->myCells.push(cell);
    cell->right->groundUnit = this;
    this->myCells.push(cell->right);
    cell->right->right->groundUnit = this;
    this->myCells.push(cell->right->right);
    for (int i = 0; i < 3; i++)
    {
        ProtoObj *cl = this->myCells.getItem(i);
        cl->bottom->groundUnit = this;
        this->myCells.push(cl->bottom);
        cl->bottom->bottom->groundUnit = this;
        this->myCells.push(cl->bottom->bottom);
    }
};