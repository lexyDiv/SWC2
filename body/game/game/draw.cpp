#include "Game.cpp"

void Game::draw()
{
    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

    if (this->gf && this->gf->init)
    {
        ctx.CreateDrawZone(this->gf->x, this->gf->y, this->gf->screenWidth, this->gf->screenHeight);

        if (this->gf->drawCell != nullptr)
        {

            this->gf->drawCell->drawCells.forEach([](ProtoObj *cell)
                                                  { cell->draw(); });
        }

        //  ctx.FillRect(this->gf->centerX, this->gf->centerY + this->gf->y, 3, 3, "black");

        ctx.CreateDrawZone(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight);
        ctx.FillRect(0, 0, this->gf->screenWidth, ctx.SCREEN_HEIGHT - this->gf->screenHeight, "blue");

        ctx.CreateDrawZone(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT);
        ctx.FillRect(this->gf->screenWidth, 0, 324, ctx.SCREEN_HEIGHT, "black");

        this->gf->miniMapDraw();
    }

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
}
