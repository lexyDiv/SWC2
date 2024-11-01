#include "../protoObj/ProtoObj.cpp"

class ProtoGame
{
public:
    ProtoGame();
    virtual ~ProtoGame();
    virtual void create();
    virtual void draw();
    virtual void preDraw();

    vector<string> pathes{
        "levels/test_1.txt",
        "levels/testBig_1.txt"};

    ProtoGameField *gf = nullptr;
};