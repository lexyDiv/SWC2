#include "isNextCellFreeToGoWay.cpp"

void Peon::selectAnAction()
{
    ProtoObj *gu = this->targetObj.unit;
    if (gu)
    {
        if (gu->name == "tree")
        {
            this->gold = 0;
            this->inFight = true;
            this->unitMenu->getConor(this, gu->cell);
            gu->lesorub = this;
        }
        else if (gu->fraction == this->fraction &&
                 gu->type != "life" &&
                 !(gu->isComplite || gu->hp < gu->hpMax))
        {
            this->inFight = true;
        } else {
            gu->wellCome(this);
        }
    }
};