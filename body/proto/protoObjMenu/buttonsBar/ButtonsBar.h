#include "../../protoUnitMenu/ProtoUnitMenu.cpp"

class ProtoObjMenu;

class ButtonsBar {
    public:
    ButtonsBar();
    ~ButtonsBar();
    int x = 750;
    int y = 500;
    int width = 250;
    int height = 200;
    ProtoObjMenu* pom = nullptr;

    void create(ProtoObjMenu* pom);
    void draw();
};