#include "isBlockedd.cpp"

void GroundUnit::iAmHere()
{
    this->cell->maxAroundCells.forEach([this](ProtoObj *cell, int index)
                                       {
                                           ProtoObj *gu = cell->groundUnit;
                                           ProtoObj *fu = cell->flyUnit;
                                     if (gu) {
                                        gu->iSeeYou(this);
                                     }
                                     if (fu) {
                                        fu->iSeeYou(this);
                                     } });
}