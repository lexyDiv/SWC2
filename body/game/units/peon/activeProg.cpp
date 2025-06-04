#include "holdGoWay.cpp"

void Peon::activeProg()
{
  if (!this->wayTakts &&
      this->wayIndex <= 5 &&
      this->isPotentialWayComplite &&
      this->orderOnWay->isComplite && 
      this->potentialWay.length)
  {
    if (!this->isIgetMyTarget)
    {

      if (this->targetObj.unit)
      {
        bool isTOValide = this->isTargetObjValide();
        if (!isTOValide)
        {
          console.log("this is not valid target");
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
        console.log("get target");
      }
    }
  }

  if (this->inFight) {
   // console.log("ready to jobe");
  }

    this->orderOnWayControl();
    this->goWay();
  
}