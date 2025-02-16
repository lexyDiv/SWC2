#include "../protoObjMenu/ProtoObjMenu.cpp"

class ProtoFraction {
    public:
    ProtoFraction();
   virtual ~ProtoFraction();
   virtual void create();

    string name = "";
    string control = "";
    Array<ProtoObj *> units;
};