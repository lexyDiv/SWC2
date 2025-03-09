#include "../../gameField/images.cpp"

void ButtonsBar::control()
{
    bool isUnit = (bool)this->pom->unit;

    if (isUnit && this->pom->unit->unitMenu->isButtons)
    {
        this->buttonsArray.forEach([this, isUnit](Array<Button *> line, int ver)
                                   { line.forEach([this, ver, isUnit](Button *button, int hor)
                                                  {
ButtonData *buttonData = this->pom->unit->unitMenu->buttonsData.getItem(this->pom->slice).getItem(ver).getItem(hor);
    button->buttonData = buttonData->update(this->pom->unit); }); });

        Button *fb = nullptr;
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
                fb = this->buttonsArray.getItem(indexY).getItem2(indexX);

                if (clickLeft && fb->buttonData)
                {
                    fb->buttonData->onClick(this->pom->unit);
                }
            };
        }
        if (fb &&
            fb->width < this->buttonGabarit)
        {
            fb->width += 1;
            fb->height += 1;
        }
        this->buttonsArray.forEach([this, fb](Array<Button *> line)
                                   { line.forEach([this, fb](Button *button)
                                                  {
            if (button != fb && button->width > button->gabarit) {
                 button->width -= 1;
                 button->height -= 1;
            } }); });
    }
};