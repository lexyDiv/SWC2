#include "create.cpp"

void TownHall::wellCome(ProtoObj *peon)
{
    if (peon->gold > 0 || peon->wood)
    {
        int index = this->contactCells.indexOf(peon->cell);
        MinData wellComeCell = index != -1 ? this->wellComeCells.getItem(index) : wellComeCell;
        if (wellComeCell.cell)
        {
            peon->unitMenu->getDeltasXY(peon, wellComeCell.cell);
            peon->inSave = true;
            peon->inOutCount = ceil(wellComeCell.min / peon->unitMenu->speed);
            peon->inOutMashtabCount = (1 - peon->inOutMashtabMin) / peon->inOutCount;
            // peon->gold = 100;
            // peon->wood = 0;
            // this->gold -= 100;
            this->potentialClients.push(peon);
            if (!this->isActive)
            {
                this->isActive = true;
                this->fraction->activeBuildings.push(this);
                //this->cell->gf->activeShahts.push(this);
            }
        }
    }
}