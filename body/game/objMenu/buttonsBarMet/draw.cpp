#include "create.cpp"

void ButtonsBar::draw() {

        ctx.FillRect(this->x, this->y, this->width, this->height, "red", 255);
        this->buttonsArray.forEach([](Button* button){
                button->draw();
        });
};