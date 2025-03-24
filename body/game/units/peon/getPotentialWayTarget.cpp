#include "getHandTarget.cpp"


bool Peon::getPotentialWayTarget(ProtoObj* cell) {
    ProtoObj* tc = this->handTargetCell ? this->handTargetCell : this->targetCell;
    if (tc && tc == cell) {
       return true;
    }
    return false;
};