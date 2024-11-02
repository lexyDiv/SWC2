#include "Game.h"

Game::~Game()
{
    delete this->gf;
    this->gf = nullptr;
}

void Game::create()
{
    this->gf = new GameField(&this->pathes[2], 1);
    this->gf->game = this;
    this->gf->create();
}
