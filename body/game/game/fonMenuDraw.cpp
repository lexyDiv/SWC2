#include "Game.cpp"

void Game::fonMenuDraw() {
    ctx.DrawImage(imager.menuFon, 0, 0, 1920, 1200, 725, 5, 295, ctx.SCREEN_HEIGHT - 10);
    ctx.FillRect(725, 5, 295, ctx.SCREEN_HEIGHT - 10, "black", 180);
};