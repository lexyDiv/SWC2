#include "../../gameField/images.cpp"

void ButtonsBar::control()
{
    if (!this->pom->gf->miniMapClick &&
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
              x > this->x + this->width ||
              y < this->y ||
              y > this->y + this->height))
        {
   
            if (clickLeft)
            {
                console.log("click");
            }
        };
    }
};