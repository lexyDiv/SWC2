#include "wellCome.cpp"

bool Shaht::isIValideOnWay(ProtoObj *unit)
{
    ProtoObj *tou = unit->targetObj.unit;
    if (tou &&
        (tou->name == "shaht" ||
         tou == this))
    {
        return true;
    }
    return false;
}