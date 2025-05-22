#include "order/Order.cpp"



class ProtoFraction {
    public:
    ProtoFraction();
   virtual ~ProtoFraction();
   virtual void create(ProtoGame* game, Nation &nation);

   virtual void orderControl();
   virtual void controller();
   virtual void activeUnitsControl();

    string name = "";
    string control = "";
    Array<ProtoObj *> units;
    Array<Order*> orders;
    Array<ProtoObj*> activeUnits;
    ProtoGame *game = nullptr;
    Array<ProtoObj *> peons;

    Nation nation = Nation();

    int unionCase = 0;

   // Nation nation = nationsHub.
};