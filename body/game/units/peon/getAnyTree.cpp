#include "isOnGetPotentialWayGetTarget.cpp"

void Peon::getAnyTree()
{
    Array<ProtoObj *> mix;
    this->fraction->fLamberMill.lamberMills.forEach([&mix, this](ProtoObj *lm)
                                                    { mix.push(lm); });
    this->fraction->fTownHoll.townHolls.forEach([&mix, this](ProtoObj *th)
                                                { mix.push(th); });
    if (mix.length)
    {
        MinData md = mix.getMinData([this](ProtoObj *item)
                                    {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        return dis; });
        ProtoObj *minDisBase = md.cell;
        console.log("logic about buildings needed !");
        return;
    }
    else
    {
    }
}