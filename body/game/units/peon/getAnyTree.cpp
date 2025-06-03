#include "isOnGetPotentialWayGetTarget.cpp"

void Peon::getAnyTree()
{
    Array<CellDis> mix;
    this->fraction->fLamberMill.lamberMills.forEach([&mix, this](ProtoObj *lm)
                                                    {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : lm->cell->x, y : lm->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        mix.push({ cell: lm, dis: dis }); });
    this->fraction->fTownHoll.townHolls.forEach([&mix, this](ProtoObj *th)
                                                {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : th->cell->x, y : th->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        mix.push({ cell: th, dis: dis }); });
    if (mix.length) {
        console.log("logic about buildings needed !");
    } else {
        
    }
}