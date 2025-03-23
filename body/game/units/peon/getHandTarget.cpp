#include "preDraw.cpp"

void Peon::getHandTarget(ProtoObj *cell) {
    // if (cell->groundUnit) {
        this->handTargetCell = cell;
        this->handTargetTimer = 200;
        this->game->unitsOnWay.push(this);

   //  }
};

