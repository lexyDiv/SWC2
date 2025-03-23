#include "Peon.cpp"

void Peon::create(ProtoObj* cell) {
    this->cell = cell;
    this->cell->groundUnit = this;

    this->name = "peon";
    this->type = "human";
    this->mapColor = {R : 0, G : 0, B : 0};
    this->image = imager.shaht;
    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y + cell->gabX / 2;

    this->animGabX = 96;
    this->animGabY = 96;
    this->animStepX = 96;
    this->animStepY = 96;

    this->animX = 0;
    this->animY = 0;
    this->hpMax = 50;
    this->hp = 50;
};