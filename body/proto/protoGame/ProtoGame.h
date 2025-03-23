#include "../protoPlane/ProtoPlane.cpp"

class ProtoGame
{
public:
    ProtoGame();
    virtual ~ProtoGame();
    virtual void create();
    virtual void draw();
    virtual void preDraw();
    virtual void fonMenuDraw();

    vector<string> pathes{
        "levels/test_1.txt",
        "levels/testBig_1.txt",
        "levels/testBig_500.txt"};

    ProtoGameField *gf = nullptr;
    ProtoObjMenu* objMenu = nullptr;
    bool isGFComplite = false;
    Array<ProtoFraction*> fractions;
};