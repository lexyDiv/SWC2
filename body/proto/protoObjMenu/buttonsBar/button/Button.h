#include "../../../protoUnitMenu/ProtoUnitMenu.cpp"

class Button {
    public:
    Button();
    ~Button();
    int x = 0;
    int y = 0;
    int centerX = 0;
    int centerY = 0;
    int gabarit = 40;
    int width = this->gabarit;
    int height = this->gabarit;
    bool isToutched = false;

    void create(int x, int y);
    void draw();

};