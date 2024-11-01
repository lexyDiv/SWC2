#include "mapInit.cpp"

void GameField::getFieldImage()
{
    if (this->path == "levels/test_1.txt")
    {
        this->miniMap = new Image(65, 65);
        this->gabarit = 65;
    } else if (this->path == "levels/testBig_1.txt")
    {
        this->miniMap = new Image(256, 256);
        this->gabarit = 256;
    }
}