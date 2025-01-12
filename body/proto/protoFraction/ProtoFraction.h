#include "../protoObj/ProtoObj.cpp"

class ProtoFraction {
    public:
    ProtoFraction();
    ~ProtoFraction();

    string name = "";
    Array<ProtoObj *> units;
};