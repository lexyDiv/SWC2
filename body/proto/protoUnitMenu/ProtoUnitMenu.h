#include "../protoObj/ProtoObj.cpp"

struct Lambda
{
    function<string(ProtoObj *unit)> fn = [](ProtoObj *unit)
    {
        return "Line";
    };
};

class ProtoUnitMenu
{
public:
    ProtoUnitMenu();
    virtual ~ProtoUnitMenu();
    virtual void create(ProtoObj *unit);

    int titleMenuX = 0;
    int titleMenuY = 0;
    bool isButtons = false;

    ProtoObj *unit = nullptr;
    Array<Lambda> infoLines;

    function<bool(ProtoObj *unit)> getIsHp = [](ProtoObj *unit)
    {
        return true;
    };

    function<bool(ProtoObj *unit)> getIsMana = [](ProtoObj *unit)
    {
        return true;
    };

    function<string(ProtoObj *unit)> getTitleName = [](ProtoObj *unit)
    {
        return "";
    };
};