#include "../protoObj/getContactAndExitCells.cpp"

ProtoPlane::ProtoPlane()
{
}

ProtoPlane::~ProtoPlane()
{
    this->contactPlanes.forEach([](ToOtherPlane *plane){
        plane->otherPlane = nullptr;
        plane->cellsToOther.clear();
        delete plane;
        plane = nullptr;
    });
}
