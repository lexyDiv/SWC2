#include "getShahts.cpp"

void TownHall::getTrees()
{
    Array<CellDis> treesData;
    this->cell->plane->trees.forEach([&treesData, this](ProtoObj *tree)
                                     {
        CellDis cd;
       PointF pointThis = {x : this->cell->x, y : this->cell->y};
       PointF pointLM = {x : tree->cell->x, y : tree->cell->y};
       Delta delta = getDeltas(&pointThis, &pointLM);
       double dis = getDis(&delta); 
       cd.cell = tree;
       cd.dis = dis;
       treesData.push(cd); });
    treesData.sort([](CellDis a, CellDis b)
                   { return a.dis < b.dis; });
    this->orderedTrees = treesData.map([](CellDis cd)
                                       { return cd.cell; });
}