#include "createUnitMenu.cpp"

bool Shaht::isBlockedd(ProtoObj *unit)
{

    int length = this->contactCells.length;
    for (int i = 0; i < length; i++)
    {
        ProtoObj *cell = this->contactCells.getItem(i);
        if (!cell->groundUnit ||
            cell->groundUnit->potentialWay.length ||
            cell->groundUnit == unit)
        {
            return false;
        }
    }

    return true;
}