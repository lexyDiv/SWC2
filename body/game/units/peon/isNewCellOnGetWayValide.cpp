#include "Peon.cpp"

bool Peon::isNewCellOnGetWayValide(ProtoObj *cell)
{

    // bool isGetTargetUnit = this->targetCell->groundUnit &&
    //                        cell->groundUnit &&
    //                        cell->groundUnit == this->targetCell->groundUnit;

    if (cell->plane == this->cell->plane)
    {
        if (!cell->groundUnit)
        {
            return true;
        }
        else if (this->targetCell->groundUnit &&
                 cell->groundUnit == this->targetCell->groundUnit)
        {
            return true;
        }
    }

    // if (
    // (!cell->groundUnit || isGetTargetUnit) &&
    // this->cell &&
    //     cell->plane == this->cell->plane)
    // {
    //     return true;
    // }
    return false;
}