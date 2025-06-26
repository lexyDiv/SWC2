#include "isGetTarget.cpp"

void Peon::createInside(ProtoObj *c)
{
    this->unitMenu = unitMenuPack.peon;

    this->cell = nullptr;
    c->game->AllUnits.push(this);
    // this->myCells.push(c);
    //  this->c->groundUnit = this;
    this->gf = c->gf;
    this->game = c->game;

    this->sight = 1;
    this->speed = 1;

    this->name = "peon";
    this->type = "life";
    this->mapColor = this->fraction->nation.mapColor;
    this->image = this->fraction->nation.peon;
    this->x = c->x;
    this->y = c->y;
    this->getGabX = c->gabX;
    this->getGabY = this->getGabX;
    this->drawIndexY = c->y + c->gabX / 2;

    this->animGabX = 100;
    this->animGabY = 100;
    this->animStepX = 100;
    this->animStepY = 100;

    this->animX = intRand(0, 8) * 100;
    this->animY = 0;
    this->hpMax = 50;
    this->hp = 50;
    this->orderOnWay = new Order;
    this->inOutTimer = 0;
    this->inSave = true;
    this->animMashtab = this->startAnimMashtab;
}