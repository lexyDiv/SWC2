#include "../fieldClick.cpp"

int GameField::get_H(ProtoObj *potentialCell, ProtoObj *finishCell)
{
    int finVer = finishCell->ver;
    int finHor = finishCell->hor;
    int pVer = potentialCell->ver;
    int pHor = potentialCell->hor;

    int deltaHor = abs(finHor - pHor);
    int deltaVer = abs(finVer - pVer);

    return deltaHor + deltaVer;
}