#include "activeUnitsControl.cpp"

void Fraction::create(ProtoGame *game, Nation &nation)
{
   // console.log("fraction created");
   this->nation = nation;
   // console.log(this->nation.color);
   this->game = game;
   ProtoObj *peon = new Peon;
   peon->fraction = this;
   peon->create(game->gf->field.getItem(10).getItem(3));

   ProtoObj *peon2 = new Peon;
   peon2->fraction = this;
   peon2->create(game->gf->field.getItem(10).getItem(6));


   this->peons.push(peon);
   this->peons.push(peon2);

   ////////////////// townHall

   ProtoObj *townHall = new TownHall;
   townHall->fraction = this;
   townHall->create(game->gf->field.getItem(2).getItem(20));
};