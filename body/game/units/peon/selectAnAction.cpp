#include "isNextCellFreeToGoWay.cpp"

void Peon::selectAnAction()
{
    ProtoObj *gu = this->targetObj.unit;
    if (gu)
    {
        if (gu->name == "tree")
        {
            this->inFight = true;
            this->unitMenu->getConor(this, gu->cell);
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