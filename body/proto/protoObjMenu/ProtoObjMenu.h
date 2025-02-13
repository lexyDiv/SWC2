#include "../protoObj/ProtoObj.cpp"

class ProtoObjMenu {
    public:
    ProtoObjMenu();
    ~ProtoObjMenu();
    Array<ProtoObj *> units;
    ProtoObj* unit = nullptr;
};