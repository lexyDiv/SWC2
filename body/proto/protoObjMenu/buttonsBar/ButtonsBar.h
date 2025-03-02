#include "../../protoUnitMenu/ProtoUnitMenu.cpp"

class ProtoObjMenu;

class ButtonsBar {
    public:
    ButtonsBar();
    ~ButtonsBar();
    int x = 0;
    int y = 0;
    int width = 200;
    int height = 200;
    ProtoObjMenu* pom = nullptr;

    void create(ProtoObjMenu* pom);
    void draw();
};