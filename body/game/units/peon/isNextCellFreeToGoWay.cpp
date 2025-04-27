#include "stendOnCell.cpp"

bool Peon::isNextCellFreeToGoWay(ProtoObj *nextCell)
{
    if (!nextCell->groundUnit)
    {
        return true;
    }
    return false;
}