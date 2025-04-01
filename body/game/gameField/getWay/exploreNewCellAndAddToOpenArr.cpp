#include "potentialWayCreate.cpp"

// Если клетка находится в открытом списке, 
// то сравниваем её значение G со значением G таким, 
// что если бы к ней пришли через текущую клетку. 
// Если сохранённое в проверяемой клетке значение G больше нового, 
// то меняем её значение G на новое, 
// пересчитываем её значение F и изменяем указатель на родителя так, 
// чтобы она указывала на текущую клетку.

void GameField::exploreNewCellAndAddToOpenArr(ProtoObj *unit, ProtoObj *fatherCell, ProtoObj *potentialCell, ProtoObj *finishCell)
{
  if (potentialCell->createCountData == this->createCount)
  {
    int G = this->get_G(fatherCell, potentialCell) + fatherCell->G;
    if (potentialCell->G > G)
    {
      potentialCell->wayFather = fatherCell;
      potentialCell->G = G;
    }
  }
  else if (
      unit->isNewCellOnGetWayValide(potentialCell))
  {
    potentialCell->wayFather = fatherCell;

    potentialCell->createCountData = this->createCount;
    int G = this->get_G(fatherCell, potentialCell);
    int H = this->get_H(potentialCell, finishCell);

    potentialCell->G = fatherCell ? G + fatherCell->G : G;
    potentialCell->H = H;
    potentialCell->F = potentialCell->G + potentialCell->H;

    this->quickArr.push(potentialCell);
    this->openArr.push(potentialCell);
  }

  // console.log("here");
}