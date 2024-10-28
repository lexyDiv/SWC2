#include "mapInit.cpp"

void GameField::getFieldImage()
{
    if (this->path == "levels/test_1.txt")
    {
        this->miniMap = new Image(65, 65);
        this->gabarit = 65;
    }
}