#include "draw.cpp"

void Game::preDraw()
{
     
        this->gf->miniMapMouseControl();
        this->gf->offsetControl();
        this->gf->fieldClick();
        this->gf->fieldClickRight();
        this->gf->trupsControl();
        this->objMenu->control();
        this->objMenu->buttonsBar.control();
        mouse.defaultKeys();
    
}