#include "create.cpp"

void Peon::stendOnCell()
{
    this->x = this->cell->x;
    this->y = this->cell->y;
    this->drawIndexY = this->y;
    this->speedTale = 0;
    this->isGetMyCell = true;
    this->potentialWay.clear();
    this->wayIndex = 0;
    this->animTimer = 0;
    this->animY = 0;
    this->holdWayCount = 0;
};