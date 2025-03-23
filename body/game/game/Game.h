#include "images.cpp"

class Game : public ProtoGame {

    public :
    Game() : ProtoGame(){};
    ~Game();

    void create() override;
    void draw() override;
    void preDraw() override;
    void fonMenuDraw() override;
    void fractionsControl() override;
};
