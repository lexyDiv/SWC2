#include "GameField.cpp"

void GameField::getMaxAroundCellsDis()
{
    this->field.forEach([](Array<ProtoObj *> arr)
                        { arr.forEach([](ProtoObj *cell)
                                      { cell->maxAroundCells.forEach([cell](ProtoObj *ac)
                                                                     {
                Delta delta = getDeltas(
                {x: cell->x, y: cell->y}, 
                {x: ac->x, y: ac->y});
                double dis = getDis(delta);
                cell->maxAroundCellsDis.push(dis); }); }); });
};