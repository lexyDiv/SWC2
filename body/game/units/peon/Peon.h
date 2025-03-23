#include "../../unitMenu/create.cpp"

class Peon : public ProtoObj {
    public:
    Peon();
    ~Peon();
    void create(ProtoObj* cell) override;
    void draw() override;
    void preDraw();

    int animTimer = 0;

};