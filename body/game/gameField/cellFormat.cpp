#include "getPotentialWay.cpp"

void GameField::cellFormat(ProtoObj* cell) {
        cell->F = 0;
        cell->G = 0;
        cell->H = 0;
        cell->createCountData = this->createCount;
        this->openArr.push(cell);
        console.log(to_string(this->openArr.length));
}