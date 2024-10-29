#include "getFieldImage.cpp"

void GameField::create()
{
    Array<string> array = readMap(&this->path);
    this->mapInit(array);
    this->getFieldImage();
    this->getAroundCells(1);
}