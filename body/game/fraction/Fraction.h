#include "../../proto/protoGame/ProtoGame.cpp"

class Fraction : public ProtoFraction {
    public:
    Fraction(): ProtoFraction(){};
    ~Fraction();
     void create(ProtoGame* game, Nation &nation) override;
     void orderControl() override;
     void controller() override;
     void activeUnitsControl() override;

};