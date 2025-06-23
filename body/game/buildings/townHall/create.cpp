#include "TownHall.cpp"

void TownHall::create(ProtoObj *cell)
{
   // console.log("townHall created !!!");
    this->createUnitMenu();
    //////////////////

     this->get4x4myCells(cell);

     ProtoObj *exitCell = cell->bottom_right->bottom_right->bottom_right->bottom_right;
     ProtoObj *centerCell = cell->bottom_right;
     this->cell = centerCell;
     this->cell->game->AllUnits.push(this);

     this->getContactAndExitCells(cell, exitCell, centerCell);
     this->getWellComeCells();
     this->getTrees();
     this->getShahts();
     this->name = "greatHall";
     this->type = "building";
     this->mapColor = this->fraction->nation.mapColor;
     this->image = this->fraction->nation.greateHall;
     this->gf = this->cell->gf;
     this->x = cell->x;
     this->y = cell->y;
     this->getGabX = cell->gabX * 4;
     this->getGabY = this->getGabX;
     this->drawIndexY = cell->y + 30;

     this->animGabX = 128;
     this->animGabY = 128;
     this->animStepX = 128;
     this->animStepY = 128;

     this->animX = 0;
     this->animY = 0;
     this->hpMax = 1200;
     this->hp = 1200;
}