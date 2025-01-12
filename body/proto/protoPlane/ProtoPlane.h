#include "../protoFraction/ProtoFraction.cpp"

struct ToOtherPlane {
    ProtoPlane *otherPlane = nullptr;
    Array<ProtoObj *> cellsToOther;
};

class ProtoPlane {
    public:
    ProtoPlane();
    virtual ~ProtoPlane();

    string type = "";
    int number = 0;
    Array<ProtoObj *> cells;
    Array<ToOtherPlane *> contactPlanes;
    Array<ProtoObj *> treeCells;
};