#include "getContinents.cpp"

void GameField::cellsIteration(function<void(ProtoObj *cell)> fn)
{
    this->field.forEach([fn](Array<ProtoObj *> arr)
                        { arr.forEach([fn](ProtoObj *cell)
                                      { fn(cell); }); });
}