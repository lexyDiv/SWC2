#include "UnitMenu.cpp"

void UnitMenu::create(ProtoObj* unit) {
  //  console.log("unit menu created");
  for (int i = 0; i < 5; i++) {
     Lambda lambda;
     this->infoLines.push(lambda);
  }
};