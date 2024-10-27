#include "../../protoObj/ProtoObj.cpp"


class Cell : public ProtoObj
{
    public:
    Cell() : ProtoObj() {};
    ~Cell();
    Color getMapColor() override;
};