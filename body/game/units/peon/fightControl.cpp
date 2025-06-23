#include "getAnyTree.cpp"

void Peon::fightControl()
{
    ProtoObj *gu = this->targetObj.unit;
    if (gu &&
        gu->name == "tree")
    {
        this->inFightTimer++;
        if (this->inFightTimer == 50)
        {
            gu->stress = 6;
            gu->hp -= 5;
            if (gu->hp <= 0)
            {
                this->cell->gf->trupsOnDelete.push(gu);
            }
        }
        if (this->inFightTimer == 70)
        {
            this->inFightTimer = 0;
            if (gu->hp <= 0)
            {
                this->targetObj.unit = nullptr;
                this->inFight = false;
                this->animY = 0;
                this->image = this->fraction->nation.peonWithWood;
                this->wood = 100;
                //// experement
                this->profession = "w";
                ProtoObj* base = this->getBaseForUnloading();
                if (base) {
                    this->orderOnWay->isComplite = false;
                    this->orderOnWay->cell = base->cell;
                }
            }
            else if (!this->orderOnWay->isComplite)
            {
                this->targetObj.unit = nullptr;
                this->inFight = false;
                this->animY = 0;
                this->profession = "";
                gu->lesorub = nullptr;
            }
        }
        gu->stressControl();
    }
};