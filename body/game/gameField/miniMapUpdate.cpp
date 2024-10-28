#include "create.cpp"

void GameField::miniMapUpdate()
{
    ctx.PixelHendler(
        this->miniMap,
        0,
        this->miniMapUpdateVer,
        this->gabarit,
        1, [this](Uint32 *pixelsArr, SDL_PixelFormat *pixelFormat)
        { this->field.getItem(this->miniMapUpdateVer).forEach([pixelsArr, pixelFormat](ProtoObj *cell, int index)
                                                              {
														  pixelsArr;
														  pixelFormat;
														  Color color = cell->getMapColor();
														  Uint8 r = color.R;
														  Uint8 g = color.G;
														  Uint8 b = color.B;
														  Uint8 a = 255;
														  Uint32 hzRes = SDL_MapRGBA(pixelFormat, r, g, b, a);
														  pixelsArr[index] = hzRes; }); });
    this->miniMapUpdateVer++;
    if (this->miniMapUpdateVer == 65)
    {
        this->miniMapUpdateVer = 0;
    }
}