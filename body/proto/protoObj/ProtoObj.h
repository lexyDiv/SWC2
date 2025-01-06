#include "../protoGameField/ProtoGameField.cpp"



class ProtoPlane;

class ProtoObj
{
public:
    ProtoObj();
    virtual ~ProtoObj();
    virtual void draw();
    virtual Color getMapColor();

    // all
    ProtoGameField *gf = nullptr;
    ProtoGame *game = nullptr;
    ProtoPlane *plane = nullptr;

    string type;
    float x = 0.0f;
    float y = 0.0f;
    float drawX = 0.0f;
    float drawY = 0.0f;
    float ver = 0;
    float hor = 0;

    int animX = 0;
    int animY = 0;
    int animGabX = 0;
    int animGabY = 0;
    int animStepX = 0;
    int animStepY = 0;
    int gabX = 0;
    int gabY = 0;
    int centerX = 0;
    int centerY = 0;

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
    Array<double> maxAroundCellsDis;
    Array<ProtoObj *> drawCells;
    Array<ProtoObj *> ripUnits;
    Array<ProtoObj *> landDecorationObjs;
    Array<ProtoObj *> guardCells;
    Array<ProtoObj *> booms;
    Array<ProtoObj *> bullets;
    ProtoObj *continent = nullptr;
    Color mapColor = {R : 0, G : 0, B : 0};
    char litera;
    int lineToOtherPlaneNumber = 0;
    int lineToTreeNumber = 0;
    int LineToMountNumber = 0;
    int cellDrawIndex = 0;
    Image* cellImage = nullptr;
    Image* cellImage2 = nullptr;
    Image* cellImage3 = nullptr;

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



