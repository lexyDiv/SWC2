#include "miniMapUpdate.cpp"



void GameField::miniMapDraw()
{
    this->miniMapUpdate();
    ctx.DrawImage(this->miniMap, 
    0, 
    0, 
    this->gabarit, 
    this->gabarit, 
    this->miniMapX, 
    this->miniMapY, 
    this->miniMapGab, 
    this->miniMapGab);
}

