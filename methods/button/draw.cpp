#include "../../body/game/game/preDraw.cpp"

void Button::draw() {
    int x = this->centerX - this->width / 2;
    int y = this->centerY - this->height / 2;
    ctx.FillRect(x, y, this->width, this->height, "blue");
   
};