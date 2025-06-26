#include "../flyingUnit/goWay.cpp"

class GroundUnit : public ProtoObj {
    public:
    GroundUnit();
    ~GroundUnit();

    void orderOnWayControl() override;
    void goWayAnimation() override;
    void inFightAnimation() override;
    void goWay() override;
    bool isNextCellFreeToGoWay(ProtoObj *nextCell) override;
    bool isNeedHoldGoWay(ProtoObj *nextCell) override;
    bool isGetTarget() override;
    bool isTargetObjValide() override;
    bool isBlockedd(ProtoObj *unit) override;
};