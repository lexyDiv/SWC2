#include "isBlockedd.cpp"

void Shaht::activeProg()
{
    this->potentialClients.forEach([this](ProtoObj *peon)
                                   {
                                       if (peon->inOutTimer < 30)
                                       {
                                           peon->x += peon->wayDeltaX;
                                           peon->y += peon->wayDeltaY;
                                           peon->inOutTimer++;
                                       }
                                       else
                                       {
                                           this->clients.push(peon);
                                           peon->cell->groundUnit = nullptr;
                                           peon->cell = nullptr; /// !!!!!!
                                           peon->inOutTimer = 0;

                                           console.log("IN !!!!");
                                       }
                                       // peon->isGetMyCell = false;
                                   });
    this->potentialClients.filterSelf([](ProtoObj *peon)
                                      {
        if (!peon->inOutTimer) {
            return true;
        }
        return false; });
};