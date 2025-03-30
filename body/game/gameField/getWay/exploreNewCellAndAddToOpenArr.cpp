#include "potentialWayCreate.cpp"

// Если соседняя клетка уже находится в открытом списке,
// то сравниваем значение величин G у клетки в открытом списке и
// текущей проверяемой клетки.
// Если прежнее значение (в открытом списке) меньше нового,
// то ничего не делаем. В обратном случае,
// у клетки в открытом списке меняем значение G на новое,
// также меняем указатель на родителя, чтобы он указывал на текущую проверяемую клетку.

void GameField::exploreNewCellAndAddToOpenArr(ProtoObj *unit, ProtoObj *fatherCell, ProtoObj *potentialCell, ProtoObj *finishCell)
{
  if (potentialCell->createCountData == this->createCount)
  {
    int G = this->get_G(fatherCell, potentialCell) + fatherCell->G;
    if (potentialCell->G >= G)
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
  }

  // console.log("here");
}