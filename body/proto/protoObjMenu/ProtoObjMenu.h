#include "../protoUnitMenu/ProtoUnitMenu.cpp"

class ProtoObjMenu {
    public:
    ProtoObjMenu();
   virtual ~ProtoObjMenu();
   virtual void create();
    Array<ProtoObj *> units;
    ProtoObj* unit = nullptr;
};