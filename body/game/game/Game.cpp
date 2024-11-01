#include "Game.h"

Game::~Game()
{
}

void Game::init()
{
    this->gf = new GameField(&this->pathes[0], 1);
    this->gf->create();
}
