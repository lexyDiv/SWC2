#include "../../../protoUnitMenu/ProtoUnitMenu.cpp"

class Button {
    public:
    Button();
    ~Button();
    int x = 0;
    int y = 0;
    int width = 40;
    int height = 40;

    void create(int x, int y);
    void draw();

};