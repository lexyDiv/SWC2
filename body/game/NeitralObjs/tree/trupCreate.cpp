#include "draw.cpp"

void Tree::trupCreate() {
    this->alpha -= 5;
    this->deleteTimer --;
    if (!this->deleteTimer) {
        this->cell->groundUnit = nullptr;
    } else if (this->deleteTimer == 49) {
        this->cell->ripUnits.push(this);
    }
};