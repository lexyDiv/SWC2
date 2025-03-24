#include "../../protoObjMenu/ProtoObjMenu.cpp"

class Order
{
public:
    Order();
    ~Order();
    ProtoObj *cell = nullptr;
    ProtoObj *unit = nullptr;
    bool isComplite = false;
    int deleteTimer = 0;
};