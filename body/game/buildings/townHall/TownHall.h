#include "../../units/peon/draw.cpp"

class TownHall : public ProtoObj {
    public:
    TownHall() : ProtoObj(){};
    ~TownHall();

    void create(ProtoObj * cell) override;
    void draw() override;
    // void createUnitMenu() override;
    // bool isBlockedd(ProtoObj *unit) override;
     void wellCome(ProtoObj *peon) override;
     void activeProg() override;
     void getTrees();
     void getShahts();
    // bool isIValideOnWay(ProtoObj *unit) override;
     MinData getPeonOutCell();

    Array<ProtoObj *> interUnits;

    // Array<ProtoObj *> orderedTrees;
    // Array<ProtoObj *> orderedShahts;
};