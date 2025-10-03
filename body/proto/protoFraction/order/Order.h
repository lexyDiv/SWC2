#include "../../protoObjMenu/ProtoObjMenu.cpp"

class Order
{
public:
    Order();
    ~Order();
    ProtoObj *cell = nullptr;
    ProtoObj *unit = nullptr;
    bool isComplite = true;
    int deleteTimer = 0;
};