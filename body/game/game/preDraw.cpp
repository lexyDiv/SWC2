#include "draw.cpp"

void Game::preDraw()
{
    if (this->gf && this->gf->init)
    {
        this->gf->fieldClick();
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
    }
}