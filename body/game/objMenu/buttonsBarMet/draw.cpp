#include "create.cpp"

void ButtonsBar::draw()
{

        ctx.FillRect(this->x, this->y, this->width, this->height, "red", 255);
        this->buttonsArray.forEach([](Array<Button *> line)
                                   { line.forEach([](Button *button)
                                                  {
                        if (button->buttonData) {
                                button->draw();
                        } }); });
};