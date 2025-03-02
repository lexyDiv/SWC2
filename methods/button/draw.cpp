#include "../../body/game/game/preDraw.cpp"

void Button::draw() {
    ctx.FillRect(this->x, this->y, this->width, this->height, "blue");
   
};