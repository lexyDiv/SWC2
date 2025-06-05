#include "activeProg.cpp"

MinData Shaht::getPeonOutCell()
{
    int ccl = this->contactCells.length;
    MinData md;
    md.cell = nullptr;
    md.index = -1;
    for (int i = 0; i < ccl; i++)
    {
        ProtoObj *cell = this->contactCells.getItem(i);
        if (!cell->groundUnit)
        {
            md.cell = cell;
            md.index = i;
            return md;
        }
    }

    int ol = this->exitCells.length;
    for (int i = 0; i < ol; i++)
    {
        ProtoObj *cell = this->exitCells.getItem(i);
        if (!cell->groundUnit)
        {
            md.cell = cell;
            md.index = -1;
            return md;
        }
    }

    return md;
}