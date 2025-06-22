#include "TownHall.cpp"

void TownHall::create(ProtoObj *cell)
{
   // console.log("townHall created !!!");
   // this->createUnitMenu();
    //////////////////

     this->get4x4myCells(cell);

    // ProtoObj *exitCell = cell->bottom->bottom->bottom_left;
     ProtoObj *centerCell = cell->bottom_right;
     this->cell = centerCell;
     this->cell->game->AllUnits.push(this);

    // this->getContactAndExitCells(cell, exitCell, centerCell);
    // this->getWellComeCells();
    // this->name = "shaht";
    // this->type = "building";
     this->mapColor = this->fraction->nation.mapColor;
     this->image = this->fraction->nation.greateHall;
     this->gf = this->cell->gf;
    // this->x = cell->x;
    // this->y = cell->y;
    // this->getGabX = cell->gabX * 3;
    // this->getGabY = this->getGabX;
     this->drawIndexY = cell->y + 50;

    // this->animGabX = 96;
    // this->animGabY = 96;
    // this->animStepX = 96;
    // this->animStepY = 96;

    // this->animX = 0;
    // this->animY = 0;
    // this->hpMax = 1000;
    // this->hp = 1000;
}