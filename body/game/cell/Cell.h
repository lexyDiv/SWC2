#include "../../protoObj/ProtoObj.cpp"


class Cell : public ProtoObj
{
    public:
    Cell() : ProtoObj() {};
    ~Cell();
    void draw(int offsetX, int offsetY) override;
    Color getMapColor() override;

};