#include "getAnyTree.cpp"

void Peon::fightControl() {
    ProtoObj *gu = this->targetObj.unit;
    if (gu &&
        gu->name == "tree") {
        this->inFightTimer ++;
        // if (this->inFightTimer < 10) {
        //     this->animY = 500;
        // } else if (this->)
    }
};