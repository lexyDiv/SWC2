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

void ProtoObj::selectAnAction() {
    
};

// bool ProtoObj::isBlocked(ProtoObj *unit) {
//     return false;
// }

bool ProtoObj::isBlockedd(ProtoObj *unit)
{
    for (int i = 0; i < this->contactCells.length; i++)
    {
        ProtoObj *cell = this->contactCells.getItem(i);
        if (!cell->groundUnit ||
            cell->groundUnit->potentialWay.length ||
            cell->groundUnit == this)
        {
            return false;
        }
    }
    return true;
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

void ProtoObj::stendOnCell() {};
void ProtoObj::stendOnCellWait() {};

