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

    int cursorX = x - drawDeltaX;
    int cursorY = y - drawDeltaY;

    // console.log(to_string(clickLeft));

    // console.log(to_string(drawDeltaX));

    if (mouse.isMove)
    {
        mouse.isMove = false;
        if (this->fieldClickPoint)
        {
           // console.log(to_string(cursorY));
            this->fieldClickPoint->moveControl(cursorX, cursorY);
        }
    }

    if (this->fieldClickPoint)
    {
        if (this->fieldClickPoint->time)
        {
            this->fieldClickPoint->time--;
        }

        if (!this->fieldClickPoint->time && this->fieldClickPoint->up)
        {
            console.log("create zone");
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
             console.log("new click");
        }
        else if (this->fieldClickPoint->time)
        {
            console.log("DOUBLE CLICK");
            delete this->fieldClickPoint;
            this->fieldClickPoint = nullptr;
        }
    }

    if (this->fieldClickPoint && clickLeftUp)
    {
        this->fieldClickPoint->up = true;
    }
};