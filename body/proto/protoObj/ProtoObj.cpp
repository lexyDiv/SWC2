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
    return {R : 255, G : 255, B : 255};
}

void ProtoObj::create(ProtoObj *cell)
{
}

int ProtoObj::getLevel()
{
    return 1;
};
void ProtoObj::createUnitMenu()
{
}
void ProtoObj::getHandTarget(ProtoObj *cell)
{
}

void ProtoObj::activeProg()
{
}

void ProtoObj::getCurrentTargetCell() {

};

void ProtoObj::getContactCells()
{
    if (this->myCells.length <= 1)
    {
        this->contactCells.copy(this->cell->aroundCells);
    }
    else
    {
        this->myCells.forEach([this](ProtoObj *cell)
                              { cell->aroundCells.forEach([this](ProtoObj *ac)
                                                          {
                if (ac->groundUnit != this) {
                   this->contactCells.push(ac);
                } }); });
    }
}
// bool ProtoObj::isOnGetPotentialWayGetTarget(ProtoObj* cell)
// {
//     return false;
// }

// bool ProtoObj::isNewCellOnGetWayValide(ProtoObj* cell) {
//     return !(bool)cell->groundUnit;
// }