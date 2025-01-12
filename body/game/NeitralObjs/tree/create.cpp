#include "draw.cpp"


void Tree::create(ProtoObj * cell) {
    cell->groundUnit = this;
    this->myCells.push(cell);
    this->name = "tree";
   // int randGX = intRand(0, 25);
    int randGY = intRand(0, 50);
    this->drawGabaritX = 40 + randGY;
    this->drawGabaritY = 50 + randGY;

    int randX = intRand(0, 15);
    int randXVec = intRand(0, 2);

    int randY = intRand(0, 15);
    int randYVec = intRand(0, 2);

    this->x = randXVec ? cell->centerX + randX : cell->centerX - randX; 
    this->y = randYVec ? cell->centerY + randY : cell->centerY - randY; 
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
