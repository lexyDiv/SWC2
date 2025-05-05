#include "../protoPlane/ProtoPlane.h"

class ProtoPlane;

void ProtoObj::getContactAndExitCells(ProtoObj *cell, ProtoObj *exitCell, ProtoObj *centerCell)
{
  Array<CellDis> proContactCells;
  this->gf = cell->gf;
  this->gf->createCount += 0.001;
  this->myCells.forEach([exitCell, &proContactCells, this](ProtoObj *mc)
                        { mc->aroundCells.forEach([mc, this, exitCell, &proContactCells](ProtoObj *ac)
                                                  {
          if (ac->plane == mc->plane &&
          ac->groundUnit != this &&
          this->gf->createCount != ac->createCountData
          ) {
            ac->createCountData = this->gf->createCount;
            CellDis cd;
            cd.cell = ac;
            Delta del = getDeltas({ x: ac->x, y: ac->y },
             { x: exitCell->x, y: exitCell->y });
            cd.dis = getDis(&del);
            proContactCells.push(cd);
          } }); });
  proContactCells.sort([](CellDis a, CellDis b)
                       { return a.dis < b.dis; });
  this->contactCells = proContactCells.map([](CellDis cd)
                                           { return cd.cell; });
  proContactCells.clear();
  cell->plane->cells.forEach([this, centerCell, &proContactCells](ProtoObj *pc)
                             {
      if (pc->createCountData != this->gf->createCount &&
      pc->groundUnit != this) {
        pc->createCountData = this->gf->createCount;
            CellDis cd;
            cd.cell = pc;
            Delta del = getDeltas({ x: pc->x, y: pc->y },
             { x: centerCell->x, y: centerCell->y });
            cd.dis = getDis(&del);
            proContactCells.push(cd);
      } });
  proContactCells.sort([](CellDis a, CellDis b)
                       { return a.dis < b.dis; });
  this->exitCells = proContactCells.map([](CellDis cd)
                                        { return cd.cell; });
};