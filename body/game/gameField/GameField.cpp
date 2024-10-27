#include "GameField.h"

GameField::GameField(string *path, int type)
{
    this->path = *path;
    this->type = type;
    this->create();
}

GameField::~GameField()
{
    if (this->miniMap != nullptr) {
        delete this->miniMap;
        this->miniMap = nullptr;
    }
    this->field.forEach([](Array<ProtoObj *> arr){
        arr.forEach([](ProtoObj *cell){
            delete cell;
            cell = nullptr;
        });
        arr.clear();
    });
    this->field.clear();
}

void GameField::create()
{
    Array<string> array = readMap(&this->path);
    this->mapInit(array);
    this->getFieldImage();
}

void GameField::mapInit(Array<string> array)
{
    array.forEach([this](string str)
                  {
        Array<ProtoObj *> arr;
        for (int i = 0; i < str.size(); i++) {
            char lit = str[i];
            Cell *cell = new Cell;
            cell->mapColor = this->getDefaultColor(lit);
            arr.push(cell);
        } 
        this->field.push(arr); });
}

void GameField::getFieldImage()
{
    if (this->path == "levels/test_1.txt")
    {
        this->miniMap = new Image(65, 65);
        this->gabarit = 65;
    }
}

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

void GameField::miniMapDraw()
{
    this->miniMapUpdate();
    ctx.DrawImage(this->miniMap, 0, 0, this->gabarit, this->gabarit, 720, 100, 285, 285);
}

Color GameField::getDefaultColor(char lit)
{
    switch (lit)
    {
    case '0':
        return ctx.ColorsMap("green");
    case 'g':
        return ctx.ColorsMap("violet");
    case 't':
        return ctx.ColorsMap("dgreen");
    case '1':
        return ctx.ColorsMap("dgreen");
    case 'w':
        return ctx.ColorsMap("blue");
    case 'S':
        return ctx.ColorsMap("yellow");
    default:
        return ctx.ColorsMap("black");
    }
}
