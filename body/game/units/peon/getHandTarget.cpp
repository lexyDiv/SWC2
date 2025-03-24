#include "preDraw.cpp"

void Peon::getHandTarget(ProtoObj *cell) {
        this->handTargetCell = cell;
        this->handTargetTimer = 200;
              this->isPotentialWayComplite = false;
        this->game->unitsOnWay.push(this);
};

