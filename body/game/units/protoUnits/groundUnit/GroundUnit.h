#include "../flyingUnit/goWay.cpp"

class GroundUnit : public ProtoObj {
    public:
    GroundUnit();
    ~GroundUnit();

   virtual void orderOnWayControl();
   virtual void goWayAnimation();
   virtual void inFightAnimation();
   virtual void goWay();
   virtual bool isNextCellFreeToGoWay(ProtoObj *nextCell);
   virtual bool isNeedHoldGoWay(ProtoObj *nextCell);
   virtual bool isGetTarget();
   virtual bool isTargetObjValide();
};