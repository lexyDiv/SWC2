#include "miniMapDraw.cpp"

void GameField::trupsControl()
{
    this->trupsOnDelete.forEach([](ProtoObj *trup)
                                { trup->trupCreate(); });
    this->trupsOnDelete.filterSelf([](ProtoObj *trup)
                                   {
     if (!trup->deleteTimer) {
        return true;
     }
     return false; });
};