#include "../protoObj/ProtoObj.cpp"

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
   // Array<function<string(ProtoObj *unit)> *> infoLines;

    function<bool(ProtoObj *unit)> getIsHp = [](ProtoObj* unit){
        return true;
    };

        function<bool(ProtoObj *unit)> getIsMana = [](ProtoObj* unit){
        return true;
    };

    function<string(ProtoObj *unit)> getTitleName = [](ProtoObj* unit){
        return "";
    };
    function<string(ProtoObj *unit)> getTitl_1_line = [](ProtoObj* unit){
        return "Line 1";
    };
    function<string(ProtoObj *unit)> getTitl_2_line = [](ProtoObj* unit){
        return "Line 2";
    };
    function<string(ProtoObj *unit)> getTitl_3_line = [](ProtoObj* unit){
        return "Line 3";
    };
    function<string(ProtoObj *unit)> getTitl_4_line = [](ProtoObj* unit){
        return "Line 4";
    };
    function<string(ProtoObj *unit)> getTitl_5_line = [](ProtoObj* unit){
        return "Line 5";
    };
    // function<bool(T item, int index, vector<T> vec)> fn
};