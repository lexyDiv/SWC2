#include "getVectorCells.cpp"

void GameField::fieldClick() {
    bool clickLeft = mouse.leftKeyDown;
    bool clickLeftUp = mouse.leftKeyUp;
    bool clickRight = mouse.rightKeyDown;
    int x = mouse.x;
    int y = mouse.y;

    float drawDeltaX = this->drawDeltaX;
    float drawDeltaY = this->drawDeltaY;

    int cursorX = x + drawDeltaX;
    int cursorY = y + drawDeltaY;

  // console.log(to_string(drawDeltaX));

    if (clickLeft) {
        this->isFieldClickHold = true;
    }
    if (clickLeftUp) {
        this->isFieldClickHold = false;
    }

   if (!(x > this->screenWidth || y < this->y)) {
          if (this->isFieldClickHold && !this->fieldClickPoint) {
        FieldClick* fcp = new FieldClick;
        fcp->clickPoint.x = cursorX;
        fcp->clickPoint.y = cursorY;
        this->fieldClickPoint = fcp;
       // console.log(to_string(cursorX));
      }
   }

       if (clickLeftUp && this->fieldClickPoint) {
        FieldClick* fcp = this->fieldClickPoint;
        int firstX, firstY, secondX, secondY;
       // string s = "click x : " + to_string(fcp->clickPoint.x) + " y : " + to_string(fcp->clickPoint.y);
       //  console.log(s);
    delete this->fieldClickPoint;
    this->fieldClickPoint = nullptr;
    }
    
};