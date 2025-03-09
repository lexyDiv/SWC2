#include "buttonsBar/ButtonsBar.cpp"

struct Zone
{
    Point a;
    Point b;
    int gabX;
    int gabY;
    bool active = false;
};

struct TitleUnit
{

    int x = 730;
    int y = 210;
    int gabX = 100;
    int gabY = 100;

    void draw(ProtoObj *unit, ProtoObjMenu *objMenu);
};

class ProtoObjMenu
{
public:
    ProtoObjMenu();
    virtual ~ProtoObjMenu();
    virtual void create(ProtoGameField *gf);
    virtual void getCandidateCells();
    virtual void control();
    virtual void draw();

    int mX, gabX, centerX;

    TitleUnit titleUnit;
    ButtonsBar buttonsBar;
    Zone zone;
    Array<ProtoObj *> units;
    Array<ProtoObj *> candidateCells;
    ProtoObj *unit = nullptr;
    ProtoGameField *gf = nullptr;
};