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
        if (peon->inOutTimer == 500) {
            peon->inOutTimer = 0;
            this->outClients.push(peon);
        } });

    this->clients.filterSelf([](ProtoObj *peon)
                             {
         if (!peon->inOutTimer) {
            return true;
        }
        return false; });

            for (int i = 0; i < this->outClients.length; i++)
    {
        ProtoObj *peon = this->outClients.getItem(i);
        if (!peon->inOutTimer)
        {
            peon->inOutCount = 0;
            MinData md = this->getPeonOutCell();
            int index = md.index;

            if (index != -1)
            {
                ProtoObj *oc = md.cell;
                MinData md = this->wellComeCells.getItem(index);
                peon->cell = md.cell;
                peon->inOutCount = ceil(md.min / peon->unitMenu->speed);
                peon->x = peon->cell->x;
                peon->y = peon->cell->y;
                peon->drawIndexY = peon->y;
                peon->unitMenu->getDeltasXY(peon, oc);
                peon->cell = oc;
                peon->inOutMashtabCount = (1 - peon->inOutMashtabMin) / peon->inOutCount;
                peon->image = peon->fraction->nation.peon;
                oc->groundUnit = peon;
                peon->gold = 100;
                peon->profession = "g";
                peon->image = peon->fraction->nation.peonWithGold;
            }
            else
            {
                MinData md = this->getPeonExtrimeOutCell();
                ProtoObj *oc = md.cell;
                peon->cell = oc;
                peon->inOutCount = 0; 
                peon->x = peon->cell->x;
                peon->y = peon->cell->y;
                peon->drawIndexY = peon->y;
                peon->inOutMashtabCount = 1; 
                peon->image = peon->fraction->nation.peon;
                oc->groundUnit = peon;
                                peon->gold = 100;
                peon->profession = "g";
                peon->image = peon->fraction->nation.peonWithGold;
            }
        }

        if (peon->inOutTimer < peon->inOutCount)
        {
            peon->x += peon->wayDeltaX;
            peon->y += peon->wayDeltaY;
            peon->drawIndexY = peon->y;
            peon->animMashtab += peon->inOutMashtabCount;

            peon->inOutTimer++;
        }
        else
        {
            peon->inOutTimer = 0;
            peon->animMashtab = 1;
            peon->inSave = false;
            peon->targetObj.unit = nullptr;
            peon->stendOnCell();
            peon->outHoldTimer = 30;
            peon->isActive = true;
            peon->fraction->activeUnits.push(peon);
        }
    };

    this->outClients.filterSelf([](ProtoObj *peon)
                                {
            if (!peon->inOutTimer) {
            return true;
        }
        return false; });
};