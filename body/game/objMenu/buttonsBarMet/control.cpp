#include "../../gameField/images.cpp"

void ButtonsBar::control()
{
    bool isUnit = (bool)this->pom->unit;

    if (isUnit && this->pom->unit->unitMenu->isButtons)
    {
        this->buttonsArray.forEach([this](Array<Button *> line, int ver)
                                   { line.forEach([this, ver](Button *button, int hor)
                                                  {
ButtonData *buttonData = this->pom->unit->unitMenu->buttonsData.getItem(this->pom->slice).getItem(ver).getItem(hor);
    button->buttonData = buttonData->update(this->pom->unit); }); });

        this->focusButton = nullptr;
        if (
            !this->pom->gf->miniMapClick &&
            !this->pom->zone.active &&
            !this->pom->gf->fieldClickPoint)
        {
            bool clickLeft = mouse.leftKeyDown;
            bool clickLeftUp = mouse.leftKeyUp;
            bool clickRight = mouse.rightKeyDown;

            int x = mouse.x;
            int y = mouse.y;

            if (!(x < this->x ||
                  x >= this->x + this->width ||
                  y < this->y ||
                  y >= this->y + this->height))
            {
                int indexX = floor((x - this->x) / (this->buttonGabarit));
                int indexY = floor((y - this->y) / (this->buttonGabarit));
                Button *candidate = this->buttonsArray.getItem(indexY).getItem2(indexX);
                this->focusButton = candidate->buttonData ? candidate : nullptr;

                if (clickLeft && this->focusButton->buttonData)
                {
                    this->focusButton->buttonData->onClick(this->pom->unit);
                }
            };
        }
        if (this->focusButton &&
            this->focusButton->width < this->buttonGabarit)
        {
            this->focusButton->width += 1;
            this->focusButton->height += 1;
        }
        this->buttonsArray.forEach([this](Array<Button *> line)
                                   { line.forEach([this](Button *button)
                                                  {
            if (button != this->focusButton && button->width > button->gabarit) {
                 button->width -= 1;
                 button->height -= 1;
            } }); });
    }
};