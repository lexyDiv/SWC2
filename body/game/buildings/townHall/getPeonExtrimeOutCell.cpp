#include "wellCome.cpp"

MinData TownHall::getPeonExtrimeOutCell()
{
    MinData md;
    md.cell = nullptr;
    md.index = -1;

    int ol = this->exitCells.length;
    for (int i = 0; i < ol; i++)
    {
        ProtoObj *cell = this->exitCells.getItem(i);
        if (!cell->groundUnit)
        {
            md.cell = cell;
            md.index = i;
            return md;
        }
    }

    return md;
}