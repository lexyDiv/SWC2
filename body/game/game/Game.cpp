#include "Game.h"

Game::~Game()
{
    delete this->gf;
    this->gf = nullptr;

    delete this->objMenu;
    this->objMenu = nullptr;

    this->AllUnits.forEach([](ProtoObj *unit)
                                    {
        delete unit;
        unit = nullptr; });

    this->fractions.forEach([](ProtoFraction *fr)
                            {
        delete fr;
        fr = nullptr; });

    delete nationsHub;
    nationsHub = nullptr;
}

void Game::create()
{
    this->gf = new GameField(&this->pathes[0], 1);
    this->gf->game = this;
    this->gf->create();

    this->objMenu = new ObjMenu;
    this->objMenu->create(this->gf);

    ////////////////////////////// fractons
    ProtoFraction *fraction = new Fraction;
    fraction->create(this, nationsHub->orcs.getItem3(0));
    fraction->control = "human";
    this->fractions.push(fraction);
    //////////////////////////////

    this->isGFComplite = true;
};
