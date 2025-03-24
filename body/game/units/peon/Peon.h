#include "../../unitMenu/create.cpp"

class Peon : public ProtoObj {
    public:
    Peon();
    ~Peon();
    void create(ProtoObj* cell) override;
    void draw() override;
    void getHandTarget(ProtoObj *cell) override;
    void preDraw();
    bool getPotentialWayTarget(ProtoObj *cell) override;

};