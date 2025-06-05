#include "isBlockedd.cpp"

void Shaht::activeProg()
{
    this->potentialClients.forEach([this](ProtoObj *peon)
                                   {
                                       if (peon->inOutTimer < 75)
                                       {
                                           peon->x += peon->wayDeltaX;
                                           peon->y += peon->wayDeltaY;
                                           peon->inOutTimer++;
                                           peon->animMashtab -= 0.008;
                                           peon->wayDeltaX *= 0.99;
                                           peon->wayDeltaY *= 0.99;
                                       }
                                       else
                                       {
                                           this->clients.push(peon);
                                           peon->cell->groundUnit = nullptr;
                                           peon->cell = nullptr;
                                           peon->inOutTimer = 0;
                                       } });
    this->potentialClients.filterSelf([](ProtoObj *peon)
                                      {
        if (!peon->inOutTimer) {
            return true;
        }
        return false; });

    this->clients.forEach([this](ProtoObj *peon)
                          {
        peon->inOutTimer ++;
        if (peon->inOutTimer == 400) {
            peon->inOutTimer = 0;
            this->outClients.push(peon);
        } });

    this->clients.filterSelf([](ProtoObj *peon)
                             {
         if (!peon->inOutTimer) {
            return true;
        }
        return false; });

    this->outClients.forEach([this](ProtoObj *peon)
                             {
                                 if (!peon->inOutTimer)
                                 {
                                     MinData md = this->getPeonOutCell();
                                     int index = md.index;
                                     ProtoObj *oc = md.cell;
                                     if (!oc)
                                     {
                                         console.log("no exit cell");
                                     }
                                     else
                                     {
                                         if (index != -1)
                                         {
                                            peon->cell = this->wellComeCells.getItem(index);
                                            peon->x = peon->cell->x;
                                            peon->y = peon->cell->y;
                                            peon->unitMenu->getDeltasXY(peon, oc);
                                            peon->cell = oc;
                                            oc->groundUnit = peon;
                                         }
                                         else
                                         {
                                         }
                                     }
                                 }
                                 peon->inOutTimer++;
                             });

    this->outClients.filterSelf([](ProtoObj *peon)
                                {
            if (!peon->inOutTimer) {
            return true;
        }
        return false; });
};