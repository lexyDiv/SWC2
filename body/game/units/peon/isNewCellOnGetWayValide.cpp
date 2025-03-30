#include "Peon.cpp"

bool Peon::isNewCellOnGetWayValide(ProtoObj *cell)
{
    if (!cell->groundUnit &&
    cell->plane->type != "sea")
    {
        return true;
    }
    return false;
}