#include "../../unitMenu/create.cpp"

class Peon : public ProtoObj {
    public:
    Peon();
    ~Peon();
    void create(ProtoObj* cell) override;
};