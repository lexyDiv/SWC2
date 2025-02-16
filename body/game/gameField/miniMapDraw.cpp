#include "miniMapUpdate.cpp"

void GameField::miniMapDraw()
{
    this->miniMapUpdate();

    ctx.FillRect(this->miniMapX + 30,
                  this->miniMapY + 30,
                  this->miniMapGab,
                  this->miniMapGab, "black", 150);

    ctx.DrawImage(this->miniMap,
                  0,
                  0,
                  this->gabarit,
                  this->gabarit,
                  this->miniMapX,
                  this->miniMapY,
                  this->miniMapGab,
                  this->miniMapGab);

    if (this->drawCell != nullptr)
    {
      float mcs = this->miniMapGab / this->gabarit;
        float x, y;
        x = (this->miniMapX + (this->drawCell->hor * this->mcs)) - this->mcs * 7;
        y = (this->miniMapY + (this->drawCell->ver * this->mcs)) - this->mcs * 7;
        ctx.StrokeRect(x, y, this->miniMapWinGab, this->miniMapWinGab, "orange");
    }
}
