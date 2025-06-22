#include "isIValideOnWay.cpp"

bool Tree::isBlockedd(ProtoObj *unit)
{
    int length = this->cell->aroundCells.length;
    for (int i = 0; i < length; i++)
    {
        ProtoObj *cell = this->cell->aroundCells.getItem(i);
        if (!cell->groundUnit ||
            cell->groundUnit == unit)
        {
            return false;
        }
    }
    return true;
};