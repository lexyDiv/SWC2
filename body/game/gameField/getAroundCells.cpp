#include "cellsIteration.cpp"


void GameField::getAroundCells(int wing, bool selfCell, function<void(ProtoObj *focusCell, ProtoObj *cellToPush)> fn)
{
    this->cellsIteration([this, wing, selfCell, fn](ProtoObj *cell)
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
                ProtoObj *pushedCell = this->field.getItem(ver).getItem(hor);
                if (!selfCell) {
                    if (cell != pushedCell) {
                    fn(cell, pushedCell);
                    }
                } else {
                   fn(cell, pushedCell);
                }
            }
        }
      } });
}
