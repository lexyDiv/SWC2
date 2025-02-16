#include "draw.cpp"

void Game::preDraw()
{
     
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
        this->gf->fieldClick();
        mouse.defaultKeys();
    
}