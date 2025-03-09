#include "../protoObj/ProtoObj.cpp"

struct Lambda
{
    function<string(ProtoObj *unit)> fn = [](ProtoObj *unit)
    {
        return "";
    };
};

struct ButtonData {
    int animX = 0;
    int animY = 0;
    int animGabX = 0;
    int animGabY = 0;
    Image *image = nullptr;
    function<void (ProtoObj *unit)> onClick = [](ProtoObj *unit){};
    function<ButtonData* (ProtoObj *unit)> update = [this](ProtoObj *unit){
        return nullptr;
    };
    // ButtonData* update(int ver, int hor) {
    //     return nullptr;
    // };
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
   // Array<Array<ButtonData*>> buttonsData;
    Array<Array<Array<ButtonData*>>> buttonsData;

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