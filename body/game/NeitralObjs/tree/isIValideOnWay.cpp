#include "drawTrup.cpp"

bool Tree::isIValideOnWay(ProtoObj *unit)
{
    ProtoObj *tou = unit->targetObj.unit;
    if (tou &&
        tou->name == "tree")
    {
        return true;
    }
    return false;
};