#include "../protoObjMenu/ProtoObjMenu.cpp"

class ProtoFraction {
    public:
    ProtoFraction();
   virtual ~ProtoFraction();
   virtual void create(ProtoGame* game);

    string name = "";
    string control = "";
    Array<ProtoObj *> units;
};