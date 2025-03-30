#include "potentialWayCreate.cpp"

void GameField::exploreNewCellAndAddToOpenArr(ProtoObj *unit, ProtoObj *fatherCell, ProtoObj *potentialCell, ProtoObj *finishCell)
{
        if (potentialCell->createCountData != this->createCount &&
            unit->isNewCellOnGetWayValide(potentialCell))
        {
                potentialCell->wayFather = fatherCell;
              if (unit->isOnGetPotentialWayGetTarget(potentialCell)) {
               // unit->isPotentialWayComplite = true;
               this->potentialWayCreate(unit, potentialCell);
                return;
              }

                potentialCell->createCountData = this->createCount;
                int G = this->get_G(fatherCell, potentialCell);
                int H = this->get_H(potentialCell, finishCell);

                potentialCell->G = fatherCell ? G + fatherCell->G : G;
                potentialCell->H = H;
                potentialCell->F = potentialCell->G + potentialCell->H;

               // this->openArr.push(potentialCell);
                this->quickArr.push(potentialCell);
        }

       // console.log("here");
}