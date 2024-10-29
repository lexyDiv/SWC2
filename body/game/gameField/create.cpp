#include "getFieldImage.cpp"

void GameField::create()
{
    Array<string> array = readMap(&this->path);
    this->mapInit(array);
    this->getFieldImage();
    this->getAroundCells(1, false, [](ProtoObj *focusCell, ProtoObj *pushedCell){
       focusCell->aroundCells.push(pushedCell);
    });
        this->getAroundCells(7, true, [](ProtoObj *focusCell, ProtoObj *pushedCell){
       focusCell->drawCells.push(pushedCell);
    });
}