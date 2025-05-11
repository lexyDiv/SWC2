#include "goWayAnimation.cpp"

bool GroundUnit::isNextCellFreeToGoWay(ProtoObj *nextCell)
{
    if (!nextCell->groundUnit)
    {
        return true;
    }
    return false;
};