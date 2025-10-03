#include "isNeedHoldGoWay.cpp"

bool GroundUnit::isBlockedd(ProtoObj *unit)
{
    for (int i = 0; i < this->cell->aroundCells.length; i++)
    {
        ProtoObj *ac = this->cell->aroundCells.getItem(i);
        if (!ac->groundUnit ||
            ac->groundUnit->potentialWay.length ||
            ac->groundUnit == unit)
        {
            return false;
        }
    }
    return true;
};