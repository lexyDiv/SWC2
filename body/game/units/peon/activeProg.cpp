#include "holdGoWay.cpp"

void Peon::activeProg()
{
  // if (this->focus) {
  //   console.log(this->profession);
  // }

  if (!this->isPotentialWayComplite)
  {
    this->noIsCompliteTimer++;
    if (this->noIsCompliteTimer >= 500)
    {
      //  console.log("i am istukan !!!");
      // this->isPotentialWayComplite = true;
    }
  }
  else
  {
    this->noIsCompliteTimer = 0;
  }
  ///////////////////////////////////////////// <= test

  if (this->isPotentialWayComplite &&
      this->pw.length)
  {
    this->potentialWay.copy(this->pw);
    this->targetObjControl(this);
    this->pw.clear();
    // ProtoObj *obj = this->potentialWay.length ? this->potentialWay.getItem(0)->groundUnit : this->targetObj.unit;
    // this->targetObj.unit = obj;
    // if (obj && obj->name == "tree")
    // {
    //    //if (obj->lesorub && obj->lesorub != this)
    //    obj->lesorub = this;
    // }
    // else
    // {
    //  // console.log("not obj");
    // }
    // // this->targetObj.unit = obj;
    // // if (!this->targetObj.unit)
    // // {

    // //   console.log("-------------");
    // //   console.log("NOT");
    // //   if (obj)
    // //   {
    // //     console.log(obj->name);
    // //   }
    // // }
  }

  if (this->isAnimyCheckNeeded)
  {
    this->isAnimyCheckNeeded = false;
    this->iAmHere();
  }

  if (this->outHoldTimer)
  {
    this->outHoldTimer--;
    if (!this->outHoldTimer && this->orderOnWay->isComplite)
    {
      this->iAmHere();
      if (this->profession == "g")
      {
        if (this->gold > 0)
        {
          ProtoObj *base = this->getBaseForUnloadingGold();
          if (base)
          {
            this->orderOnWay->isComplite = false;
            this->orderOnWay->cell = base->cell;
          }
        }
        else
        {
          ProtoObj *base = this->getAnyShaht();
          if (base)
          {
            this->orderOnWay->isComplite = false;
            this->orderOnWay->cell = base->cell;
          }
        }
      }
      else if (this->profession == "w")
      {
        ProtoObj *tree = this->getAnyTree();
        if (tree)
        {
          this->orderOnWay->isComplite = false;
          this->orderOnWay->cell = tree->cell;
        }
        else
        {
          this->profession = "";
          this->targetObj.unit = nullptr;
          console.log("no tree 1");
        }
      }
    }
    else if (this->orderOnWay->isComplite)
    {
      return;
    }
  }

  ///////////////////////////////////////////////////////////////
  if (!this->wayTakts &&
      this->wayIndex <= 5 &&
      this->isPotentialWayComplite &&
      this->orderOnWay->isComplite &&
      this->potentialWay.length &&
      !this->holdWayCount &&
      !this->inFight)
  {
    if (!this->isIgetMyTarget)
    {
      ProtoObj *to = this->targetObj.unit;
      if (to)
      {
        bool isTOValide = this->isTargetObjValide();
        if (!isTOValide)
        {
          // this->targetCell = nullptr;
          // this->preTargetCell = nullptr;
          // this->targetObj.unit = nullptr;
          this->stendOnCell();
          if (this->profession == "w")
          {
            ProtoObj *newTree = this->getAnyTree();
            if (newTree)
            {
              this->orderOnWay->isComplite = false;
              this->orderOnWay->cell = newTree->cell;
            }
            else
            {
              this->profession = "";
              this->targetObj.unit = nullptr;
              console.log("no tree 2");
            }
          }
          else if (this->profession == "g")
          {
            ProtoObj *newShaht = this->getAnyShaht();
            if (newShaht)
            {
              this->orderOnWay->isComplite = false;
              this->orderOnWay->cell = newShaht->cell;
            }
            else
            {
              this->profession = "";
              this->targetObj.unit = nullptr;
              console.log("no shaht");
            }
          }
          else
          {

            this->profession = "";
            console.log(this->targetObj.unit->name);
            this->targetObj.unit = nullptr;
          }
        
        }
      }

      this->isGetTarget();
      if (this->isIgetMyTarget)
      {
        this->targetCell = nullptr;
        this->preTargetCell = nullptr;
        this->stendOnCell();
        this->isIgetMyTarget = false;
        this->selectAnAction();
        // return;
        // console.log("get target");
      }
    }
    else
    {
    }
  }

  if (this->inFight)
  {
    this->fightControl();
  }
  else
  {
    this->goWay();
    this->orderOnWayControl();
  }
}