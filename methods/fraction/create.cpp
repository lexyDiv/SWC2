#include "activeUnitsControl.cpp"

void Fraction::create(ProtoGame* game) {
   // console.log("fraction created");
   this->game = game;
   ProtoObj* peon = new Peon;
   peon->fraction = this;
   peon->create(game->gf->field.getItem(14).getItem(20));
};