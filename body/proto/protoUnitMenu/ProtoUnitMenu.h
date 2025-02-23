#include "../protoObj/ProtoObj.cpp"

class ProtoUnitMenu
{
public:
    ProtoUnitMenu();
    virtual ~ProtoUnitMenu();
    virtual void create(ProtoObj *unit);
    bool hp = false;
    int titleMenuX = 0;
    int titleMenuY = 0;
    ProtoObj *unit = nullptr;
    function<string(ProtoObj *unit)> getTitleName = [](ProtoObj* unit){
        return "";
    };
    function<string(ProtoObj *unit)> getTitl_1_line = [](ProtoObj* unit){
        return "";
    };
    function<string(ProtoObj *unit)> getTitl_2_line = [](ProtoObj* unit){
        return "";
    };
    function<string(ProtoObj *unit)> getTitl_3_line = [](ProtoObj* unit){
        return "";
    };
    function<string(ProtoObj *unit)> getTitl_4_line = [](ProtoObj* unit){
        return "";
    };
    function<string(ProtoObj *unit)> getTitl_5_line = [](ProtoObj* unit){
        return "";
    };
    // function<bool(T item, int index, vector<T> vec)> fn
};