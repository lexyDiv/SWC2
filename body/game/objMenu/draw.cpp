#include "control.cpp"

void ObjMenu::draw() {
    if (this->unit) {
        this->titleUnit.draw(this->unit, this);
        this->buttonsBar.draw();
    }
};