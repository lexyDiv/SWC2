#include "../../body/game/game/preDraw.cpp"

void Button::draw(ProtoObj* unit)
{
    Image *image = this->buttonData->getImage(unit);
    int animX = this->buttonData->animX;
    int animY = this->buttonData->animY;
    int animGabX = this->buttonData->animGabX;
    int animGabY = this->buttonData->animGabY;


    int x = this->centerX - this->width / 2;
    int y = this->centerY - this->height / 2;
   // ctx.FillRect(x, y, this->width, this->height, "blue");
    ctx.DrawImage(image, animX, animY, animGabX, animGabY, x, y, this->width, this->height);
};