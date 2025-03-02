#include "control.cpp"

void ButtonsBar::create(ProtoObjMenu* pom) {
    this->pom = pom;
    for (int ver = 0; ver < 4; ver++) {
       for (int hor = 0; hor < 5; hor++) {
                  Button* button = new Button;
          button->create(this->x + hor * 50, this->y + ver * 50);
       this->buttonsArray.push(button);
       }
    }
   // console.log(to_string(this->buttonsArray.getItem(0)->width));
};