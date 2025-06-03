#include "../protoUnits/sweemingUnit/goWay.cpp"

class Peon : public GroundUnit
{
public:
    Peon();
    ~Peon();
    void create(ProtoObj *cell) override;
    void draw() override;
    void getHandTarget(ProtoObj *cell) override;
    void preDraw();
    void getCurrentTargetCell() override;
    void activeProg() override;
    void stendOnCell() override;
    void stendOnCellWait() override;
    bool isGetTarget() override;
    bool isTargetObjValide() override;

    void getAnyTree();

    // void orderOnWayControl() override;
    //  void goWayAnimation() override;
    // void goWay() override;
    // bool isNextCellFreeToGoWay(ProtoObj *nextCell) override;
    //  bool isNeedHoldGoWay(ProtoObj *nextCell) override;
    // bool isOnGetPotentialWayGetTarget(ProtoObj *cell) override;
    // bool isNewCellOnGetWayValide(ProtoObj *cell) override;
};