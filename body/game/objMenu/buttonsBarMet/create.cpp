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
         button->create(this->x + 5 + hor * 50, this->y + 5 + ver * 50);
         line.push(button);
      }
      this->buttonsArray.push(line);
   }
};