#include "button/Button.cpp"

class ProtoObjMenu;

class ButtonsBar {
    public:
    ButtonsBar();
    ~ButtonsBar();
    int slice = 0;
    int x = 750;
    int y = 500;
    int buttonGabarit = 50;
    int lines = 4;
    int columns = 5;
    int width = this->buttonGabarit * this->columns;
    int height = this->buttonGabarit * this->lines;
    ProtoObjMenu* pom = nullptr;
    Array<Array<Button *>> buttonsArray;

    void create(ProtoObjMenu* pom);
    void draw();
    void control();
};