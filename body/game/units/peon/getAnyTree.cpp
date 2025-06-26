#include "isOnGetPotentialWayGetTarget.cpp"

ProtoObj *Peon::getAnyTree()
{

    ProtoObj* t = this->getTreeNear();
    if (t) {
        return t;
    }

    ProtoObj *base = this->getBaseForUnloading();
    if (base)
    {
        for (int i = 0; i < base->orderedTrees.length; i++)
        {
            ProtoObj *tree = base->orderedTrees.getItem(i);
            if (tree->hp > 0 &&
                !tree->lesorub)
            {
                return tree;
            }
        }
    }
    else
    {
        // console.log(to_string(this->cell->plane->trees.length));
        MinData md = this->cell->plane->trees.getMinData([this](ProtoObj *item)
                                                         {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = !item->lesorub && item->hp > 0 ? getDis(&delta) : 10000000;
                                                        return dis; });
        ProtoObj *minDisTree = md.cell->hp > 0 && !md.cell->lesorub ? md.cell : nullptr;
        return minDisTree;
    }
   // this->plane->trees.clear();
    return nullptr;
}