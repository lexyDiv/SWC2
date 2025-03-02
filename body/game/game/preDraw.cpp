#include "draw.cpp"

void Game::preDraw()
{
     
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
        this->gf->fieldClick();
        this->objMenu->buttonsBar.control();
        mouse.defaultKeys();
    
}