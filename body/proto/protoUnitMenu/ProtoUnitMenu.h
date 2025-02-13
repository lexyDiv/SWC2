#include "../protoObj/ProtoObj.cpp"

class ProtoUnitMenu {
    public:
    ProtoUnitMenu();
   virtual ~ProtoUnitMenu();
   virtual void create(ProtoObj* unit);

   ProtoObj* unit = nullptr;
};