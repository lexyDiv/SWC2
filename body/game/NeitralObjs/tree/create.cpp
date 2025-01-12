#include "draw.cpp"


void Tree::create(ProtoObj * cell) {
    cell->groundUnit = this;
    this->myCells.push(cell);
    this->name = "tree";
    int randGX = intRand(5, 15);
    int randGY = intRand(5, 40);
    this->drawGabaritX = 50 + randGX;
    this->drawGabaritY = 80 + randGY;
    this->x = (cell->x - 11 - cell->gabX /2) + intRand(1, cell->gabX);
    this->y = (cell->y - cell->gabY /2) + intRand(1, cell->gabY / 2) - this->drawGabaritY / 2;
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
    this->animTakt = intRand(0, 15);
    this->gf = cell->gf;
}
