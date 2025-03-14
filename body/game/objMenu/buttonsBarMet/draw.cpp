#include "create.cpp"

void ButtonsBar::draw()
{

        if (this->focusButton && this->focusButton->buttonData)
        {
                int infoStringFontSize = 15;

                string infoString = this->focusButton->buttonData->infoString;
                int infoStringGabX = infoString.size() * (infoStringFontSize * 0.7);
                int infoStringX = this->pom->centerX - infoStringGabX / 2;

                menuText.draw(infoString, infoStringX, this->y - 22, infoStringFontSize, 255, 255, 255);
        }

        ctx.FillRect(this->x, this->y, this->width, this->height, "red", 255);
        this->buttonsArray.forEach([](Array<Button *> line)
                                   { line.forEach([](Button *button)
                                                  {
                        if (button->buttonData) {
                                button->draw();
                        } }); });
};