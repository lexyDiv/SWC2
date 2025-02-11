#include "ProtoObj.h"

void ProtoObj::get2x2myCells(ProtoObj *cell) {
    cell->groundUnit = this;
    this->myCells.push(cell);
    ProtoObj* cell2 = cell->right;
    cell2->groundUnit = this;
    this->myCells.push(cell2);
    ProtoObj* cell3 = cell->bottom;
    cell3->groundUnit = this;
    this->myCells.push(cell3);
    ProtoObj* cell4 = cell2->bottom;
    cell4->groundUnit = this;
    this->myCells.push(cell4);
};