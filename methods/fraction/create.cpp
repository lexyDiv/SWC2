#include "../buttonData/createOut.cpp"

void Fraction::create(ProtoGame* game) {
   // console.log("fraction created");
   
   ProtoObj* peon = new Peon;
   peon->fraction = this;
   peon->create(game->gf->field.getItem(2).getItem(1));
};