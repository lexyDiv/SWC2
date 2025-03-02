#include "create.cpp"

void ButtonsBar::draw() {

        ctx.FillRect(this->x, this->y, this->width, this->height, "black", 150);
        this->buttonsArray.forEach([](Button* button){
                button->draw();
        });
};