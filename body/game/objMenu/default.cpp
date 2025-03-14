#include "ObjMenu.cpp"

void ObjMenu::defaultData() {
        this->units.clear();
        this->unit = nullptr;
        int cellSize = this->gf->cellSize;
        this->zone.active = false;
        this->slice = 0;
        this->buttonsBar.buttonsArray.forEach([this](Array<Button *> line)
                               { line.forEach([this](Button *button)
                                              {
            button->width = button->gabarit;
            button->height = button->gabarit;
            }); 
            });
};