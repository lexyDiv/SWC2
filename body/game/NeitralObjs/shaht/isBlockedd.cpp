#include "createUnitMenu.cpp"

bool Shaht::isBlockedd(ProtoObj *unit)
{

    int length = this->myCells.length;
    for (int i = 0; i < length; i++)
    {
        ProtoObj *cell = this->myCells.getItem(i);
        if (!cell->groundUnit ||
            cell->groundUnit == unit)
        {
            return false;
        }
    }

    return true;
}