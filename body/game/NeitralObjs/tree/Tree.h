#include "../shaht/draw.cpp"

class Tree : public ProtoObj {
     public:
     Tree() : ProtoObj(){};
     ~Tree();

    void create(ProtoObj * cell) override;
    void draw() override;
};