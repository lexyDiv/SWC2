#include "../../gameField/images.cpp"

void ButtonsBar::control()
{
         Button* fb = nullptr;
    if (
        !this->pom->gf->miniMapClick &&
        !this->pom->zone.active &&
        !this->pom->gf->fieldClickPoint &&
        this->pom->unit &&
        this->pom->unit->unitMenu->isButtons)
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

            if (clickLeft)
            {
            }
        };
    }
    if (fb &&
        fb->width < this->buttonGabarit)
    {
        fb->width += 1;
        fb->height += 1;
    }
    this->buttonsArray.forEach([this, fb](Array<Button*> line){
        line.forEach([this, fb](Button* button){
            if (button != fb && button->width > button->gabarit) {
                 button->width -= 1;
                 button->height -= 1;
            }
        });
    });
};