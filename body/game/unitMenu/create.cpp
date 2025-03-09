#include "UnitMenu.cpp"

void UnitMenu::create(ProtoObj* unit) {
  //  console.log("unit menu created");
  for (int i = 0; i < 5; i++) {
     Lambda lambda;
     this->infoLines.push(lambda);
  }

  for (int ver = 0; ver < 4; ver++) {
    Array<ButtonData*> line;
    for (int hor = 0; hor < 5; hor++) {
       ButtonData *buttonData = new ButtonData;
       line.push(buttonData);
     // line.push(nullptr);
    };
    this->buttonsData.push(line);
  };

};