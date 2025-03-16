#include "buttonData/ButtonData.cpp"

struct Lambda
{
    function<string(ProtoObj *unit)> fn = [](ProtoObj *unit)
    {
        return "";
    };
};


class ProtoUnitMenu
{
public:
    ProtoUnitMenu();
    virtual ~ProtoUnitMenu();
    virtual void create();
    virtual void createShaht();

    // int titleMenuX = 0;
    // int titleMenuY = 0;

    function<Point(ProtoObj *unit)> titleMenuXY = [](ProtoObj *unit)
    {
        Point point = {x : 0, y : 0};
        return point;
    };

    bool isButtons = false;

    ProtoObj *unit = nullptr;
    Array<Lambda> infoLines;
    // Array<Array<ButtonData*>> buttonsData;
    Array<Array<Array<ButtonData *>>> buttonsData;

    function<bool(ProtoObj *unit)> getIsHp = [](ProtoObj *unit)
    {
        return false;
    };

    function<bool(ProtoObj *unit)> getIsMana = [](ProtoObj *unit)
    {
        return false;
    };

    function<string(ProtoObj *unit)> getTitleName = [](ProtoObj *unit)
    {
        return "";
    };
};