#include "getVectorCells.cpp"

void GameField::fieldClick() {
    bool clickLeft = mouse.leftKeyDown;
    bool clickLeftUp = mouse.leftKeyUp;
    bool clickRight = mouse.rightKeyDown;
    int x = mouse.x;
    int y = mouse.y;

    if (clickLeft) {
        this->isFieldClickHold = true;
    }
    if (clickLeftUp) {
        this->isFieldClickHold = false;
    }

    if (this->isFieldClickHold) {
      //  console.log("hold");
    }

    if (clickLeftUp) {
        string s = "click x : " + to_string(x) + " y : " + to_string(y);
        // console.log(s);
    }
    
};