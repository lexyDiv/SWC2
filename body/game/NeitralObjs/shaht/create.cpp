#include "Shaht.cpp"

struct CellDis {
  ProtoObj* cell = nullptr;
  double dis = 0.0;
};

void Shaht::create(ProtoObj* cell) {
    cell->groundUnit = this;
    this->myCells.push(cell);
    cell->right->groundUnit = this;
    this->myCells.push(cell->right);
    cell->right->right->groundUnit = this;
    this->myCells.push(cell->right->right);
    for (int i = 0; i < 3; i++) {
        ProtoObj* cl = this->myCells.getItem(i);
        cl->bottom->groundUnit = this;
        this->myCells.push(cl->bottom);
        cl->bottom->bottom->groundUnit = this;
        this->myCells.push(cl->bottom->bottom);
    }

    ProtoObj* exitCell = cell->bottom->bottom->bottom_left;
    ProtoObj* centerCell = cell->bottom_right;

    Array<CellDis> proContactCells;
    this->gf = cell->gf;
    this->gf->createCount += 0.00001;
    this->myCells.forEach([exitCell, &proContactCells, this](ProtoObj* mc){
        mc->aroundCells.forEach([mc, this, exitCell, &proContactCells](ProtoObj* ac){
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
          }
        });
    });
    proContactCells.sort([](CellDis a, CellDis b){
      return a.dis < b.dis;
    });
    this->contactCells = proContactCells.map([](CellDis cd){
      return cd.cell;
    });
    proContactCells.clear();
    cell->plane->cells.forEach([this, centerCell, &proContactCells](ProtoObj* pc){
      if (pc->createCountData != this->gf->createCount &&
      pc->groundUnit != this) {
        pc->createCountData = this->gf->createCount;
            CellDis cd;
            cd.cell = pc;
            Delta del = getDeltas({ x: pc->x, y: pc->y },
             { x: centerCell->x, y: centerCell->y });
            cd.dis = getDis(&del);
            proContactCells.push(cd);
      }
    });
     proContactCells.sort([](CellDis a, CellDis b){
      return a.dis < b.dis;
    });
    this->exitCells = proContactCells.map([](CellDis cd){
      return cd.cell;
    });

    this->name = "shaht";
    this->mapColor = {R: 255, G: 255, B: 0};
    this->image = shaht;
    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX * 3;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y + 20;

    this->animGabX = 96;
    this->animGabY = 96;
    this->animStepX = 96;
    this->animStepY = 96;

    this->animX = 0;
    this->animY = 0;

  //  console.log(to_string(this->myCells.length));

}