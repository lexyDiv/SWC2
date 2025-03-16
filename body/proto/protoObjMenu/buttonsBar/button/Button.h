#include "../../../protoUnitMenu/ProtoUnitMenu.cpp"

class Button {
    public:
    Button();
    ~Button();
     int animX = 0;
     int animY = 0;
     int animGabX = 0;
     int animGabY = 0;
    int centerX = 0;
    int centerY = 0;
    int gabarit = 40;
    int width = this->gabarit;
    int height = this->gabarit;
    bool isToutched = false;
    ButtonData *buttonData = nullptr;

    void create(int x, int y);
    void draw(ProtoObj* unit);

};