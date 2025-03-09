#include "ObjMenu.cpp"

void ObjMenu::defaultData() {
        this->units.clear();
        this->unit = nullptr;
        int cellSize = this->gf->cellSize;
        this->zone.active = false;
        this->slice = 0;
};