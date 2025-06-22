#include "fightControl.cpp"

ProtoObj *Peon::getBaseForUnloadingGold()
{
    if (this->fraction->fTownHoll.townHolls.length)
    {
        MinData md = this->fraction->fTownHoll.townHolls.getMinData([this](ProtoObj *item)
                                                                    {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        return dis; });
        ProtoObj *minDisBase = md.cell;
        return minDisBase;
    }
    return nullptr;
};