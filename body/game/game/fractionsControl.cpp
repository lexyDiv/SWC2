#include "fonMenuDraw.cpp"

void Game::fractionsControl() {
    this->fractions.forEach([](ProtoFraction* fr){
         fr->controller();
    });
};