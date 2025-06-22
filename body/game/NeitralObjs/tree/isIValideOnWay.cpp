#include "drawTrup.cpp"

bool Tree::isIValideOnWay(ProtoObj *unit)
{
    ProtoObj *tou = unit->targetObj.unit;
    if (tou &&
        tou->name == "tree" &&
        !this->lesorub)
    {
        return true;
    }
    return false;
};