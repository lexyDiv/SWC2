#include "holdGoWay.cpp"

void Peon::activeProg()
{
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
      ProtoObj* to = this->targetObj.unit;
      if (to)
      {
        bool isTOValide = this->isTargetObjValide();
        if (!isTOValide)
        {
        this->targetCell = nullptr;
        this->preTargetCell = nullptr;
        this->stendOnCell();
        if (to->name == "tree") {
         ProtoObj* newTree = this->getAnyTree();
         if (newTree) {
          this->orderOnWay->isComplite = false;
          this->orderOnWay->cell = newTree->cell;
         }
        }
       // this->targetObj.unit = nullptr;
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
      //  console.log("get target");
      }
    }
  }

  if (this->inFight) {
   this->fightControl();
  } else {
    this->goWay();
    this->orderOnWayControl();
  }

}