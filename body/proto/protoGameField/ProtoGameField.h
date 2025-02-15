#include "../images.cpp"

class ProtoObj;
class ProtoGame;
class ProtoPlane;
class ProtoFraction;
class ProtoObjMenu;
struct FieldClick;

class ProtoGameField
{
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
    virtual void miniMapMouseControl();
    virtual void miniMapHoldLeftMouseKey();
    virtual void getContinents();
    virtual void getMaxAroundCellsDis();
    virtual void getToOtherPlaneCellsNumber();
    virtual void getToTreeCellLineNumber();
    virtual void getCellImageCellDrawIndexCellUnitInit();
    virtual void getVectorCells(ProtoObj *cell);
    virtual void fieldClick();

    virtual Color getDefaultColor(char lit);

    // ProtoObjMenu* objMenu = nullptr;
    ProtoGame *game = nullptr;
    Array<ProtoFraction *> fractions;

    Array<Array<ProtoObj *>> field;

    Array<ProtoPlane *> planes;
    Array<string> goldData;
    Array<string> oilData;

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
    int centerX = this->screenWidth / 2;  //+ this->x;
    int centerY = this->screenHeight / 2; //+ this->y;
    float offsetX = 0;
    float offsetY = 0;
    float drawDeltaX = 0;
    float drawDeltaY = 0;
    int drawOffsetX = 0;
    int drawOffsetY = 0;
    int width = 0;
    int height = 0;
    int offsetStep = 10;
    bool init = false;
    double createCount = 0.0;
    // this->miniMap, 0, 0, this->gabarit, this->gabarit, 732, 100, 285, 285
    ////////////////////////////// => miniMap
    float miniMapX = 732;
    float miniMapY = 48;
    float miniMapGab = 285;
    float miniMapClickX = 0;
    float miniMapClickY = 0;
    bool miniMapClick = false;
    float miniMapWinGab = 0;
    float mcs = 0.0f;
    int dx = 0;
    int dy = 0;
    //////////////////////////// <= miniMap

    ///////////////// => fieldClick
    bool isFieldClickHold = false;
    //////////////// <= fieldClick

    FieldClick *fieldClickPoint = nullptr;

private:
};

struct FieldClick
{
    Point clickPoint;
    int time = 20;
    bool up = false;
    int firstX, firstY, secX, secY, gabX, gabY;
    void moveControl(int cursorX, int cursorY)
    {
        
        int X = this->clickPoint.x;
        int Y = this->clickPoint.y;
        if (X <= cursorX)
        {
            this->firstX = X;
            this->secX = cursorX;
        }
        else
        {
            this->firstX = cursorX;
            this->secX = X;
        }

        if (Y <= cursorY)
        {
            this->firstY = Y;
            this->secY = cursorY;
        }
        else
        {
            this->firstY = cursorY;
            this->secY = Y;
        }
        this->gabX = this->secX - this->firstX;
        this->gabY = this->secY - this->firstY;
    };
};