#include "../../Listenner.h"


class ProtoObj;

class ProtoGameField {
    public:
    ProtoGameField(string *path, int type);
   virtual ~ProtoGameField();
   virtual void create();
   virtual void mapInit(Array<string> array);
   virtual void getFieldImage();
   virtual void miniMapUpdate();
   virtual void miniMapDraw();
   virtual void cellsIteration(function<void(ProtoObj *cell)> fn);
   virtual void getAroundCells(int wing, bool selfCell, function<void(ProtoObj *focusCell, ProtoObj *cellToPush)> fn);
   virtual void offsetControl();

   virtual Color getDefaultColor(char lit);
    Array<Array<ProtoObj *>> field;
    Image *miniMap = nullptr;
    ProtoObj *drawCell = nullptr;
    string path;
    int type;
    int miniMapUpdateVer = 0;
    int gabarit = 0;
    int screenWidth = 720;
    int screenHeight = 720;
    int cellSize = this->screenHeight / 15;
    int x = 0;
    int y = 48;
    int centerX = this->screenWidth / 2 ;//+ this->x;
    int centerY = this->screenHeight / 2 ; //+ this->y;
    int offsetX = 0;
    int offsetY = 0;
    int drawOffsetX = 0;
    int drawOffsetY = 0;
    int width = 0;
    int height = 0;
    int offsetStep = 10;
    bool init = false;

private:
};