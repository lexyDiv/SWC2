#include "../protoObj/ProtoObj.cpp"

class ProtoUnitMenu
{
public:
    ProtoUnitMenu();
    virtual ~ProtoUnitMenu();
    virtual void create(ProtoObj *unit);
    string titleName = "";
    bool resurs = false;
    bool hp = false;
    int titleMenuX = 0;
    int titleMenuY = 0;
    ProtoObj *unit = nullptr;
};