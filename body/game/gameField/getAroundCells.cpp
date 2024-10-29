#include "cellsIteration.cpp"

void GameField::getAroundCells(int wing)
{
    this->cellsIteration([this, wing](ProtoObj *cell)
                         {
      int minVer = cell->ver - wing;
      int maxVer = cell->ver + wing;
      for (int ver = minVer; ver <= maxVer; ver++) {
        int minHor = cell->hor - wing;
        int maxHor = cell->hor + wing;
        for (int hor = minHor; hor <= maxHor; hor++) {
                    if (
            ver >= 0 && 
            ver < this->gabarit &&
            hor >= 0 &&
            hor < this->gabarit) {
               // console.log("here");
                ProtoObj *pushedCell = this->field.getItem(ver).getItem(hor);
                if (cell != pushedCell) {
                    cell->aroundCells.push(pushedCell);
                }
        }
        }
      } });
}