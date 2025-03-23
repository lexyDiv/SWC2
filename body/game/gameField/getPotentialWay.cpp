#include "fieldClick.cpp"

void GameField::getPotentialWay(ProtoObj* unit) {
    unit->potentialWay.clear();
    while(!unit->isPotentialWayComplite) {
        unit->isPotentialWayComplite = true;
    }
    console.log("scan way for unit");
    
};