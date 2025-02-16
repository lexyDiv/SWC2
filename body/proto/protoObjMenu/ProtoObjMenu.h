#include "../protoUnitMenu/ProtoUnitMenu.cpp"

struct Zone {
    Point a;
    Point b;
    int gabX;
    int gabY;
    bool active = false;
};

struct TitleUnit {
    int x = 730;
    int y = 280;
    int gabX = 100;
    int gabY = 100;
   // ProtoObj* unit = nullptr;

    void draw(ProtoObj* unit) {
        ctx.DrawText(750, 250, 20, unit->unitMenu->titleName);
        ctx.DrawImage(imager.icons, unit->unitMenu->titleMenuX, unit->unitMenu->titleMenuY, 50, 42, this->x, this->y, this->gabX, this->gabY);
        if (unit->unitMenu->resurs) {
          int resurs;
          string resursName = "";
          if (unit->gold >= 0) {
            resurs = unit->gold;
            resursName = "Gold";
          } else {
            resurs = unit->oil;
            resursName = "Oil";
          }
          string resStr = resursName + " : " + to_string(resurs);
          ctx.DrawText(750, 400, 20, resStr);
        }
    };
};

class ProtoObjMenu {
    public:
    ProtoObjMenu();
   virtual ~ProtoObjMenu();
   virtual void create();
   virtual void getCandidateCells();
   virtual void control();
   virtual void draw();

   
   TitleUnit titleUnit;
   Zone zone;
    Array<ProtoObj *> units;
    Array<ProtoObj* > candidateCells;
    ProtoObj* unit = nullptr;
    ProtoGameField* gf = nullptr;
};