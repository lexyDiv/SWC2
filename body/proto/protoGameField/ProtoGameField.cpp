#include "ProtoGameField.h"

ProtoGameField::ProtoGameField(string *path, int type)
{
    
    this->path = *path;
    this->type = type;
   // this->create();
}

ProtoGameField::~ProtoGameField()
{
}

void ProtoGameField::create()
{
    console.log("create proto");
}

void ProtoGameField::mapInit(Array<string> array)
{
}

void ProtoGameField::getFieldImage()
{
}

void ProtoGameField::miniMapUpdate()
{
}

void ProtoGameField::miniMapDraw()
{
   
}

void ProtoGameField::cellsIteration(function<void(ProtoObj *cell)> fn)
{
}

void ProtoGameField::getAroundCells(int wing, bool selfCell, function<void(ProtoObj *focusCell, ProtoObj *cellToPush)> fn)
{
}

void ProtoGameField::offsetControl()
{
}

Color ProtoGameField::getDefaultColor(char lit)
{
    return Color();
}

void ProtoGameField::miniMapMouseControl()
{
}

void ProtoGameField::miniMapHoldLeftMouseKey()
{
}

void ProtoGameField::getContinents()
{
}

void ProtoGameField::getMaxAroundCellsDis()
{
}

void ProtoGameField::getToOtherPlaneCellsNumber()
{
}

void ProtoGameField::getToTreeCellLineNumber()
{
}

void ProtoGameField::getCellImageCellDrawIndexCellUnitInit()
{
}

void ProtoGameField::getVectorCells(ProtoObj *cell)
{
}

void ProtoGameField::fieldClick()
{
}

void ProtoGameField::fieldClickRight()
{
}

void ProtoGameField::getPotentialWay(ProtoObj* unit)
{
}

double ProtoGameField::getMinCellsDis(ProtoObj *cell, ProtoObj *cell2)
{
    
    return 0.0;
}

////////////////////////////////////

// class GF : public ProtoGameField {
//     public:
//     GF(string *path, int type) : ProtoGameField(path, type){};
//     ~GF();
//     void create() override;
// };

// GF::~GF()
// {
// }

// void GF::create()
// {
//     console.log("create GF");
// }
