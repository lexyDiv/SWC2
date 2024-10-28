#include "getDefaultColor.cpp"

void GameField::mapInit(Array<string> array)
{
    array.forEach([this](string str)
                  {
        Array<ProtoObj *> arr;
        for (int i = 0; i < str.size(); i++) {
            char lit = str[i];
            Cell *cell = new Cell;
            cell->mapColor = this->getDefaultColor(lit);
            arr.push(cell);
        } 
        this->field.push(arr); });
}