#include "Shaht.cpp"

void Shaht::create(ProtoObj* cell) {

   this->unitMenu = new UnitMenu;
   this->unitMenu->create(this);

   this->get3x3myCells(cell);

    ProtoObj* exitCell = cell->bottom->bottom->bottom_left;
    ProtoObj* centerCell = cell->bottom_right;

    this->getContactAndExitCells(cell, exitCell, centerCell);

    this->name = "shaht";
    this->mapColor = {R: 255, G: 255, B: 0};
    this->image = imager.shaht;
    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX * 3;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y + 20;

    this->animGabX = 96;
    this->animGabY = 96;
    this->animStepX = 96;
    this->animStepY = 96;

    this->animX = 0;
    this->animY = 0;
    cell->plane->shahts.push(this);
}