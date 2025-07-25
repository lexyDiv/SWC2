#include "getAnyTree.cpp"

ProtoObj *Peon::getAnyShaht()
{
    ProtoObj *th = this->getBaseForUnloadingGold();
    if (th)
    {
        if (this->gold > 0)
        {
            return th;
        }
        for (int i = 0; i < th->orderedShahts.length; i++)
        {
            ProtoObj *shaht = th->orderedShahts.getItem(i);
            if (shaht->gold > 0)
            {
                return shaht;
            }
        }
    }

    MinData md = this->cell->plane->shahts.getMinData([this](ProtoObj *item)
                                                      {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = item->gold > 0 && item->hp > 0 ? getDis(&delta) : 10000000;
                                                        return dis; });
    ProtoObj *minDisShaht = md.cell && md.cell->gold > 0 ? md.cell : nullptr;
    return minDisShaht;

    // return nullptr;
}