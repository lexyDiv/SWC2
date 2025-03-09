#include "../../unitMenu/create.cpp"

class Shaht : public ProtoObj {
    public:
    Shaht() : ProtoObj(){};
    ~Shaht();

    void create(ProtoObj * cell) override;
    void draw() override;
    void createUnitMenu() override;
};