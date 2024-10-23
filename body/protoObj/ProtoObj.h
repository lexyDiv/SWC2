#include "../../Listenner.h"

class ProtoObj
{
public:
    ProtoObj();
   virtual ~ProtoObj();
    virtual void draw();

    // all

    float x = 0.0f;
    float y = 0.0f;
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
    Image *image = nullptr;

    // units
    bool isActive = false;
    int speed = 0;
    int hp = 0;
    int attack = 0;
    int armor = 0;
    int mana = 0;
    ProtoObj *cell = nullptr;
    vector<ProtoObj *> *enemys = nullptr;
    vector<ProtoObj *> *myWay = nullptr;
    vector<ProtoObj *> *cells2X2 = nullptr;
    vector<ProtoObj *> *contactCells = nullptr;

    // cells

    ProtoObj *groundUnit = nullptr;
    ProtoObj *flyUnit = nullptr;
    vector<ProtoObj *> *aroundCells = nullptr;
    vector<ProtoObj *> *drawCells = nullptr;
    vector<ProtoObj *> *ripUnits = nullptr;
    vector<ProtoObj *> *landDecorationObjs = nullptr;
    vector<ProtoObj *> *guardCells = nullptr;
    vector<ProtoObj *> *booms = nullptr;
    vector<ProtoObj *> *bullets = nullptr;
    ProtoObj *continent = nullptr;

    // bullets

    // flying units
    float z = 0.0f;

    // sea units

    // buildings
    vector<ProtoObj *> *myCells = nullptr;

    // land objects

    // wall

private:
    string type;
};