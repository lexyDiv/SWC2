#include "trupCreate.cpp"

void Peon::takeDamage(int damage)
{
    if (this->hp)
    {
        this->hp -= damage;
        if (this->hp <= 0)
        {
            this->hp = 0;
            this->gf->trupsOnDelete.push(this);
            this->cell->ripUnits.push(this);
            this->deleteTimer = 1000;
        }
    }
};