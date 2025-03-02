#include "control.cpp"

void ButtonsBar::create(ProtoObjMenu *pom)
{
   this->pom = pom;
   for (int ver = 0; ver < this->lines; ver++)
   {
      Array<Button *> line;
      for (int hor = 0; hor < this->columns; hor++)
      {
         Button *button = new Button;
         button->create(this->x + (this->buttonGabarit / 2) + hor * this->buttonGabarit, this->y + (this->buttonGabarit / 2) + ver * 50);
         line.push(button);
      }
      this->buttonsArray.push(line);
   }
};