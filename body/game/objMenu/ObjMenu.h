#include "buttonsBarMet/draw.cpp"



class ObjMenu : public ProtoObjMenu {
    public:
    ObjMenu() : ProtoObjMenu() {};
    ~ObjMenu();

    void create(ProtoGameField* gf) override;
    void getCandidateCells() override;
    void control() override;
    void draw() override;
};