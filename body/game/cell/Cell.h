#include "../NeitralObjs/create.cpp"


class Cell : public ProtoObj
{
    public:
    Cell() : ProtoObj() {};
    ~Cell();
    void draw() override;
    Color getMapColor() override;

};