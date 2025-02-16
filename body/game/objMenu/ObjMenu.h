#include "../gameField/images.cpp"



class ObjMenu : public ProtoObjMenu {
    public:
    ObjMenu() : ProtoObjMenu() {};
    ~ObjMenu();

    void create() override;
    void getCandidateCells() override;
    void control() override;
    void draw() override;
};