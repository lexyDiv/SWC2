#include "../protoUnits/sweemingUnit/goWay.cpp"

class Peon : public GroundUnit
{
public:
    Peon();
    ~Peon();
    void create(ProtoObj *cell) override;
    void draw() override;
    void getHandTarget(ProtoObj *cell) override;
    void getCurrentTargetCell() override;
    void getCurrentTargetCell2() override;
    void activeProg() override;
    void stendOnCell() override;
    void stendOnCellWait() override;
    bool isGetTarget() override;
    bool isTargetObjValide() override;
    void selectAnAction() override;
    void fightControl() override;
    void createInside(ProtoObj* c) override; 


    ProtoObj* getAnyTree() override;
    ProtoObj *getAnyShaht() override;
    ProtoObj* getTreeNear() override;
    ProtoObj* getBaseForUnloading() override;
    ProtoObj* getBaseForUnloadingGold() override;
        void preDraw() override;

    // void orderOnWayControl() override;
    //  void goWayAnimation() override;
    // void goWay() override;
    // bool isNextCellFreeToGoWay(ProtoObj *nextCell) override;
    //  bool isNeedHoldGoWay(ProtoObj *nextCell) override;
    // bool isOnGetPotentialWayGetTarget(ProtoObj *cell) override;
    // bool isNewCellOnGetWayValide(ProtoObj *cell) override;
};