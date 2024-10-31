#include "ProtoGameField.cpp"



class ProtoObj
{
public:
    ProtoObj();
    virtual ~ProtoObj();
    virtual void draw();
    virtual Color getMapColor();

    // all
    ProtoGameField *gf = nullptr;

    string type;
    float x = 0.0f;
    float y = 0.0f;
    float ver = 0;
    float hor = 0;
    int drawX = 0;
    int drawY = 0;
    int animX = 0;
    int animY = 0;
    int animGabX = 0;
    int animGabY = 0;
    int animStepX = 0;
    int animStepY = 0;
    int gabX = 0;
    int gabY = 0;
    Color mapColor = {R : 0, G : 0, B : 0};
    Image *image = nullptr;

    // units
    bool isActive = false;
    int speed = 0;
    int hp = 0;
    int attack = 0;
    int armor = 0;
    int mana = 0;
    ProtoObj *cell = nullptr;
    Array<ProtoObj *> enemys;
    Array<ProtoObj *> myWay;
    Array<ProtoObj *> cells2X2;
    Array<ProtoObj *> contactCells;

    // cells

    ProtoObj *groundUnit = nullptr;
    ProtoObj *flyUnit = nullptr;
    Array<ProtoObj *> aroundCells;
    Array<ProtoObj *> maxAroundCells;
    Array<ProtoObj *> drawCells;
    Array<ProtoObj *> ripUnits;
    Array<ProtoObj *> landDecorationObjs;
    Array<ProtoObj *> guardCells;
    Array<ProtoObj *> booms;
    Array<ProtoObj *> bullets;
    ProtoObj *continent = nullptr;

    // bullets

    // flying units
    float z = 0.0f;

    // sea units

    // buildings
    Array<ProtoObj *> myCells;

    // land objects

    // wall

private:
};



