#include "button/Button.cpp"

class ProtoObjMenu;

class ButtonsBar {
    public:
    ButtonsBar();
    ~ButtonsBar();
    int slice = 0;
    int x = 750;
    int y = 500;
    int width = 250;
    int height = 200;
    ProtoObjMenu* pom = nullptr;
    Array<Button *> buttonsArray;

    void create(ProtoObjMenu* pom);
    void draw();
};