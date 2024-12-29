#include "getToTreeCellLineNumber.cpp"

void GameField::getToOtherPlaneCellsNumber()
{
    this->planes.forEach([](ProtoPlane *plane)
                         { plane->contactPlanes.forEach([plane](ToOtherPlane *op)
                                                        { op->cellsToOther.forEach([plane](ProtoObj *cell)
                                                                                   { cell->aroundCells.forEach([plane](ProtoObj *contactCell)
                                                                                                               {
              if (!contactCell->lineToOtherPlaneNumber &&
              contactCell->plane == plane) {
                 contactCell->lineToOtherPlaneNumber = 2;
              } }); }); }); });
};