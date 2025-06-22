#include "get2x2myCells.cpp"

void ProtoObj::getWellComeCells()
{
    this->contactCells.forEach([this](ProtoObj *cell)
                               {
                                   MinData md = this->myCells.getMinData([this, cell](ProtoObj *item)
                                                                         {
                                                        PointF pointThis = {x : cell->x, y : cell->y};
                                                        PointF pointLM = {x : item->x, y : item->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        return dis; });
                                    this->wellComeCells.push(md); });
};