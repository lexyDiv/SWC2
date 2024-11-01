#include "draw.cpp"

void Game::preDraw()
{
    if (this->gf->init)
    {
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
    }
}