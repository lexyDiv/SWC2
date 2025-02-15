#include "../protoUnitMenu/ProtoUnitMenu.cpp"

struct Zone {
    Point a;
    Point b;
    int gabX;
    int gabY;
    bool active = false;
};

class ProtoObjMenu {
    public:
    ProtoObjMenu();
   virtual ~ProtoObjMenu();
   virtual void create();
   virtual void getCandidateCells();
   Zone zone;
    Array<ProtoObj *> units;
    Array<ProtoObj* > candidateCells;
    ProtoObj* unit = nullptr;
    ProtoGameField* gf = nullptr;
};