#include "../protoUnitMenu/create.cpp"

class ProtoObjMenu {
    public:
    ProtoObjMenu();
    ~ProtoObjMenu();
    Array<ProtoObj *> units;
    ProtoObj* unit = nullptr;
};