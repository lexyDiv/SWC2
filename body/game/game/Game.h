#include "../gameField/miniMapMouseControl.cpp"

class Game : public ProtoGame {

    public :
    Game() : ProtoGame(){};
    ~Game();

    void init() override;
    void draw() override;
    void preDraw() override;

};
