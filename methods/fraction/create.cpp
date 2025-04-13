#include "activeUnitsControl.cpp"

void Fraction::create(ProtoGame* game) {
   // console.log("fraction created");
   this->game = game;
   ProtoObj* peon = new Peon;
   peon->fraction = this;
   peon->create(game->gf->field.getItem(10).getItem(3));

      ProtoObj* peon2 = new Peon;
   peon2->fraction = this;
   peon2->create(game->gf->field.getItem(10).getItem(15));
};