#include "potentialWayCreate.cpp"

// Если клетка находится в открытом списке,
// то сравниваем её значение G со значением G таким,
// что если бы к ней пришли через текущую клетку.
// Если сохранённое в проверяемой клетке значение G больше нового,
// то меняем её значение G на новое,
// пересчитываем её значение F и изменяем указатель на родителя так,
// чтобы она указывала на текущую клетку.

// [3, 1] уже находится в открытом списке,
// поэтому сравниваем её значение F со значением F таким,
// что если бы мы пришли на неё через текущую клетку.
// Это значения 60 и 64, соответственно, а значит, данные проверяемой клетки не нужно обновлять.
// Клетки с индексами [4, 1] и [4, 2] добавляем в открытый список,
// предварительно вычислив их значения величин G, H и F,
// а также установив указатель на родительскую клетку

void GameField::exploreNewCellAndAddToOpenArr(ProtoObj *unit, ProtoObj *fatherCell, ProtoObj *potentialCell, ProtoObj *finishCell)
{
  if (potentialCell->explored != this->createCount)
  {
    if (potentialCell->createCountData == this->createCount)
    {
      int G = this->get_G(fatherCell, potentialCell) + fatherCell->G;
      int F = G + potentialCell->H;
      if (potentialCell->F > F)
      {
        potentialCell->wayFather = fatherCell;
        potentialCell->G = G;
        potentialCell->F = F;
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

      this->openArr.push(potentialCell);
      // this->quickArr.push(potentialCell);
    }
  }
}