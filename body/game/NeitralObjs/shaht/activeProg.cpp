#include "isBlockedd.cpp"

void Shaht::activeProg()
{
    this->potentialClients.forEach([this](ProtoObj *peon)
                                   {
                                       if (peon->inOutTimer < peon->inOutCount)
                                       {
                                           peon->x += peon->wayDeltaX;
                                           peon->y += peon->wayDeltaY;
                                           peon->inOutTimer++;
                                           peon->animMashtab -= peon->inOutMashtabCount;
                                       }
                                       else
                                       {
                                           this->clients.push(peon);
                                           peon->cell->groundUnit = nullptr;
                                           peon->cell = nullptr;
                                           peon->inOutTimer = 0;
                                           peon->animMashtab = peon->inOutMashtabMin;
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
        if (peon->inOutTimer == 100) {
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
                                     peon->inOutCount = 0;
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
                                            MinData md = this->wellComeCells.getItem(index);
                                            peon->cell = md.cell;
                                            peon->inOutCount = ceil(md.min / peon->unitMenu->speed);
                                            peon->x = peon->cell->x;
                                            peon->y = peon->cell->y;
                                            peon->unitMenu->getDeltasXY(peon, oc);
                                            peon->cell = oc;
                                            peon->inOutMashtabCount = (1 - peon->inOutMashtabMin) / peon->inOutCount;
                                            oc->groundUnit = peon;
                                         }
                                         else
                                         {
                                         }
                                     }
                                 }

                                 if (peon->inOutTimer < peon->inOutCount) {
                                           peon->x += peon->wayDeltaX;
                                           peon->y += peon->wayDeltaY;
                                           peon->animMashtab += peon->inOutMashtabCount;

                                 peon->inOutTimer++;
                                 }
                                 else {
                                    peon->inOutTimer = 0;
                                    peon->animMashtab = 1;
                                    peon->inSave = false;
                                    peon->isGetMyCell = true;
                                    peon->targetCell = nullptr;
                                    peon->preTargetCell = nullptr;
                                    peon->targetObj.unit = nullptr;
                                    peon->wayTakts = 0;
                                    peon->stendOnCell();
                                 } });

    this->outClients.filterSelf([](ProtoObj *peon)
                                {
            if (!peon->inOutTimer) {
            return true;
        }
        return false; });

      //  console.log(to_string(this->outClients.length));
};