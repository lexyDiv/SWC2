#include "../protoObjMenu/ProtoObjMenu.cpp"

class ProtoFraction {
    public:
    ProtoFraction();
   virtual ~ProtoFraction();
   virtual void create();

    string name = "";
    Array<ProtoObj *> units;
};