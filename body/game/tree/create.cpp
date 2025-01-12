#include "draw.cpp"


void Tree::create(ProtoObj * cell) {
    cell->groundUnit = this;
    this->myCells.push(cell);
    this->name = "tree";
    this->x = cell->x + intRand(1, cell->gabX - 1);
    this->y = cell->y + intRand(1, cell->gabY - 1);
    this->hp = 50;
    this->animGabX = 200;
    this->animGabY = 200;
    this->animStepX = 200;
    this->animStepY = 200;
    int randImg = intRand(0, 2);
    this->image = randImg ? tree1 : tree2;
    this->image2 = randImg ? tree1Trup : tree2Trup;
    this->animX = 200 * intRand(0, 4);
    this->animY = 200 * intRand(0, 4);
}
