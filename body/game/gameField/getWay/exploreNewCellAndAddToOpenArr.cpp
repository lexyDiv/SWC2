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

void GameField::exploreNewCellAndAddToOpenArr(ProtoObj *unit, ProtoObj *fatherCell, ProtoObj *potentialCell)
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
      int H = this->get_H(potentialCell, unit->targetCell);

      potentialCell->G = fatherCell ? G + fatherCell->G : G;
      potentialCell->H = H;
      potentialCell->F = potentialCell->G + potentialCell->H;

      this->openArr.push(potentialCell);
    }
  }
}

void GameField::exploreNewCellAndAddToOpenArr2(ProtoObj *unit, ProtoObj *fatherCell, ProtoObj *potentialCell)
{
  if (potentialCell->explored2 != this->createCount2)
  {
    if (potentialCell->createCountData2 == this->createCount2)
    {
      int G2 = this->get_G2(fatherCell, potentialCell) + fatherCell->G2;
      int F2 = G2 + potentialCell->H2;
      if (potentialCell->F2 > F2)
      {
        potentialCell->wayFather2 = fatherCell;
        potentialCell->G2 = G2;
        potentialCell->F2 = F2;
      }
    }
    else if (
        unit->isNewCellOnGetWayValide(potentialCell))
    {
      potentialCell->wayFather2 = fatherCell;

      potentialCell->createCountData2 = this->createCount2;
      int G2 = this->get_G2(fatherCell, potentialCell);
      int H2 = this->get_H2(potentialCell, unit->targetCell);

      potentialCell->G2 = fatherCell ? G2 + fatherCell->G2 : G2;
      potentialCell->H2 = H2;
      potentialCell->F2 = potentialCell->G2 + potentialCell->H2;

      this->openArr2.push(potentialCell);
    }
  }
}