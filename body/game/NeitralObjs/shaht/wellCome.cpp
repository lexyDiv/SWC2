#include "Shaht.cpp"

void Shaht::wellCome(ProtoObj *peon)
{
   int index = this->contactCells.indexOf(peon->cell);
   ProtoObj *wellComeCell = index != -1 ? this->wellComeCells.getItem(index) : nullptr;
   if (wellComeCell)
   {
      peon->unitMenu->getDeltasXY(peon, wellComeCell);
      peon->inSave = true;
      this->potentialClients.push(peon);
      if (!this->isActive) {
         this->isActive = true;
         this->cell->gf->activeShahts.push(this);
      }
   }
};