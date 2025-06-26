#include "preDraw.cpp"

ProtoObj* Peon::getTreeNear() {
    for (int i = 0; i < this->cell->maxAroundCells.length; i++) {
        ProtoObj *obj = this->cell->maxAroundCells.getItem(i)->groundUnit;
        if (obj &&
        obj->name == "tree" &&
        !obj->lesorub &&
        obj->hp > 0) {
            return obj;
        }
    }
    return nullptr;
}