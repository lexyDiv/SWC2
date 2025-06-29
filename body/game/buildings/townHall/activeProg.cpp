#include "getPeonOutCell.cpp"

bool ok = false;

void TownHall::activeProg()
{

    // if (!ok)
    // {
    //     ok = true;

    //     for (int i = 0; i < 1000; i++)
    //     {
    //         this->fraction->unitCount++;
    //         ProtoObj *peon = new Peon;
    //         peon->persNum = this->fraction->unitCount;
    //         peon->fraction = this->fraction;
    //         peon->createInside(this->cell);
    //         peon->profession = "w";
    //         this->fraction->peons.push(peon);
    //         this->outClients.push(peon);
    //         this->cell->game->allPeons.push(peon);
    //     }
    // }
    if (this->createTimer)
    {
        this->createTimer--;
        if (!this->createTimer)
        {
            //  console.log("create peon");
            if (this->fraction->peons.length < 10000) // 6000 crash
            {
                this->createTimer = 300; // this->createTimerMax;
            }
            this->fraction->unitCount ++;
            ProtoObj *peon = new Peon;
            peon->persNum = this->fraction->unitCount;
            peon->fraction = this->fraction;
            peon->createInside(this->cell);
            peon->profession = "w";
            this->fraction->peons.push(peon);
            this->outClients.push(peon);
            this->cell->game->allPeons.push(peon);
            //    delete peon;
            //    peon = nullptr;
        }
    }

    ////////////////////////
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
                                           if (this->fraction->fTownHoll.level_3_townHollsCount) {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 150 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 150 : this->fraction->wood;
                                           } else if (this->fraction->fTownHoll.level_2_townHollsCount) {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 125 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 125 : this->fraction->wood;
                                           } else {
                                            this->fraction->gold = peon->gold ? this->fraction->gold + 100 : this->fraction->gold;
                                            this->fraction->wood = peon->wood ? this->fraction->wood + 100 : this->fraction->wood;
                                           }
                                           peon->wood = 0;
                                           peon->gold = 0;
                                        //  console.log(to_string(peon->animMashtab));
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

    // this->outClients.forEach([this](ProtoObj *peon)
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
            }
            else
            {
                MinData md = this->getPeonExtrimeOutCell();
                // index = md.index;
                ProtoObj *oc = md.cell;
                // MinData md = this->wellComeCells.getItem(index);
                peon->cell = oc;
                peon->inOutCount = 0; // ceil(md.min / peon->unitMenu->speed);
                peon->x = peon->cell->x;
                peon->y = peon->cell->y;
                peon->drawIndexY = peon->y;
                // peon->unitMenu->getDeltasXY(peon, oc);
                // peon->cell = oc;
                peon->inOutMashtabCount = 1; // (1 - peon->inOutMashtabMin) / peon->inOutCount;
                peon->image = peon->fraction->nation.peon;
                oc->groundUnit = peon;
                // console.log("no exit cell 2");
                // return;
            }
            //   }
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
            //// experement
            // ProtoObj *base = peon->getBase
            // peon->orderOnWay->isComplite = false;
            // peon->orderOnWay->cell = peon
        }
    };

    this->outClients.filterSelf([](ProtoObj *peon)
                                {
            if (!peon->inOutTimer) {
            return true;
        }
        return false; });
}