#include "trupCreate.cpp"

void Peon::takeDamage(int damage)
{
    if (this->hp && !this->inSave)
    {
        this->hp -= damage;
        if (this->hp <= 0)
        {
            this->hp = 0;
            this->gf->trupsOnDelete.push(this);
            this->cell->ripUnits.push(this);
            this->deleteTimer = 3000;
            this->animY = 1000;
            /// no lesorub needed !!!!
        }
    }
};