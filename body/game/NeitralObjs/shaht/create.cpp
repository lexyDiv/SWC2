#include "Shaht.cpp"

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

    this->name = "shaht";
    this->mapColor = {R: 255, G: 255, B: 0};
    this->image = shaht;
    this->x = cell->x + cell->gabX * 1.5;
    this->y = cell->y + cell->gabY * 1.5;
    this->drawIndexY = cell->y + 20;

    this->animGabX = 96;
    this->animGabY = 96;
    this->animStepX = 96;
    this->animStepY = 96;

    this->animX = 0;
    this->animY = 0;

    this->gf = cell->gf;

  //  console.log(to_string(this->myCells.length));

}