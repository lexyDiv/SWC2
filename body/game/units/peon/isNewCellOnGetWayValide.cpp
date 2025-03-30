#include "Peon.cpp"

bool Peon::isNewCellOnGetWayValide(ProtoObj *cell)
{
    if (!cell->groundUnit && this->cell &&
        cell->plane == this->cell->plane)
    {
        return true;
    }
    return false;
}