#include "../../proto/protoGame/ProtoGame.cpp"

class Fraction : public ProtoFraction {
    public:
    Fraction(): ProtoFraction(){};
    ~Fraction();
     void create(ProtoGame* game) override;

};