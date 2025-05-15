#include "../oil/draw.cpp"

class Tree : public ProtoObj {
     public:
     Tree() : ProtoObj(){};
     ~Tree();

    void create(ProtoObj * cell) override;
    void draw() override;
    bool isBlockedd(ProtoObj *unit) override;
};