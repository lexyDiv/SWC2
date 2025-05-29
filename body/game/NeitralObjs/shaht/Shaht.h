#include "../../units/peon/draw.cpp"

class Shaht : public ProtoObj {
    public:
    Shaht() : ProtoObj(){};
    ~Shaht();

    void create(ProtoObj * cell) override;
    void draw() override;
    void createUnitMenu() override;
    bool isBlockedd(ProtoObj *unit) override;
};