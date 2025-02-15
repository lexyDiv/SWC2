#include "getVectorCells.cpp"

void GameField::fieldClick()
{
    bool clickLeft = mouse.leftKeyDown;
    bool clickLeftUp = mouse.leftKeyUp;
    bool clickRight = mouse.rightKeyDown;

    int x = mouse.x;
    int y = mouse.y;

    float drawDeltaX = this->drawDeltaX;
    float drawDeltaY = this->drawDeltaY;


    if (this->fieldClickPoint)
    {
    int cursorX = x <= this->screenWidth ? x - drawDeltaX : this->screenWidth - drawDeltaX;
    int cursorY = y >= this->y ? y - drawDeltaY : this->y - drawDeltaY;

        this->fieldClickPoint->moveControl(cursorX, cursorY);

        if (this->fieldClickPoint->time)
        {
            this->fieldClickPoint->time--;
        }

        if (!this->fieldClickPoint->time && this->fieldClickPoint->up)
        {
          //  console.log("create zone");
          ProtoObjMenu* objMenu = this->game->objMenu;
        objMenu->zone.active = true;
        objMenu->zone.a = {x: this->fieldClickPoint->firstX, y: this->fieldClickPoint->firstY};
        objMenu->zone.b = {x: this->fieldClickPoint->secX, y: this->fieldClickPoint->secY};
        objMenu->zone.gabX = this->fieldClickPoint->gabX;
        objMenu->zone.gabY = this->fieldClickPoint->gabY;

            delete this->fieldClickPoint;
            this->fieldClickPoint = nullptr;
        }
    }

    if (!(x > this->screenWidth || y < this->y) && clickLeft)
    {
        if (!this->fieldClickPoint)
        {
            FieldClick *fc = new FieldClick;
            fc->clickPoint.x = x - drawDeltaX;
            fc->clickPoint.y = (y) - drawDeltaY;
            this->fieldClickPoint = fc;
           // console.log(to_string(fc->clickPoint.y));
            // console.log("new click");
        }
        else if (this->fieldClickPoint->time)
        {
           // console.log("DOUBLE CLICK");
            delete this->fieldClickPoint;
            this->fieldClickPoint = nullptr;
        }
    }

    if (this->fieldClickPoint && clickLeftUp)
    {
        this->fieldClickPoint->up = true;
    }
};