#include "Oil.cpp"

void Oil::create(ProtoObj* cell) {
    this->get2x2myCells(cell);
    ProtoObj* exitCell = cell->left;
    ProtoObj* centerCell = cell->bottom_right;

    this->getContactAndExitCells(cell, exitCell, centerCell);

    this->name = "oil";
    this->mapColor = {R: 0, G: 0, B: 0};
    this->image = oilPoint;
     this->x = cell->x;
     this->y = cell->y;
     this->getGabX = cell->gabX * 2;
     this->getGabY = this->getGabX;
     this->drawIndexY = cell->bottom->y + cell->gabY;

    // this->animGabX = 96;
    // this->animGabY = 96;
    // this->animStepX = 96;
    // this->animStepY = 96;

    // this->animX = 0;
    // this->animY = 0;
     cell->plane->oils.push(this);
};