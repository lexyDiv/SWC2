#include "fieldClick.cpp"

void GameField::getPotentialWay(ProtoObj* unit) {
    unit->potentialWay.clear();
    console.log("scan way for unit");
    unit->isPotentialWayComplite = true;
};