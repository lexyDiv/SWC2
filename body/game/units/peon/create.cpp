#include "Peon.cpp"

void Peon::create(ProtoObj* cell) {
  
    this->unitMenu = unitMenuPack.peon;

    this->cell = cell;
    this->cell->groundUnit = this;
    this->gf = cell->gf;

    this->sight = 1;
    this->speed = 1;

    this->name = "peon";
    this->type = "life";
    this->mapColor = {R : 255, G : 255, B : 255};
    this->image = imager.peonRed;
    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y + cell->gabX / 2;

    this->animGabX = 100;
    this->animGabY = 100;
    this->animStepX = 100;
    this->animStepY = 100;

    this->animX = intRand(0, 8) * 100;
    this->animY = 0;
    this->hpMax = 50;
    this->hp = 50;
};