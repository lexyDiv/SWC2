#include "get3x3myCells.cpp"




ProtoObj::ProtoObj()
{
}

ProtoObj::~ProtoObj()
{
      //  console.log("protoObj delete");

}

void ProtoObj::draw()
{
}

Color ProtoObj::getMapColor()
{
    return {R: 255, G: 255, B: 255};
}

void ProtoObj::create(ProtoObj *cell)
{
}

int ProtoObj::getLevel() {
    return 1;
};
void ProtoObj::createUnitMenu()
{
}
void ProtoObj::getHandTarget(ProtoObj *cell)
{
}
bool ProtoObj::isOnGetPotentialWayGetTarget(ProtoObj* cell)
{
    return false;
}

bool ProtoObj::isNewCellOnGetWayValide(ProtoObj* cell) {
    return !(bool)cell->groundUnit;
}