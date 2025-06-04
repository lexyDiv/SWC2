#include "getAnyTree.cpp"

void Peon::fightControl() {
    ProtoObj *gu = this->targetObj.unit;
    if (gu &&
        gu->name == "tree") {
        this->inFightTimer ++;
        if (this->inFightTimer == 50) {
            gu->stress = 6;
            gu->hp -= 5;
            if (!gu->hp) {
                //console.log("kaput");
                this->cell->gf->trupsOnDelete.push(gu);
                this->targetObj.unit = nullptr;
            }
        }
        if (this->inFightTimer == 70) {
            this->inFightTimer = 0;
        }
        gu->stressControl();
    }
};