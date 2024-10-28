#include "miniMapUpdate.cpp"

void GameField::miniMapDraw()
{
    this->miniMapUpdate();
    ctx.DrawImage(this->miniMap, 0, 0, this->gabarit, this->gabarit, 720, 100, 285, 285);
}