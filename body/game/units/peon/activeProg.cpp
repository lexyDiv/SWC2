#include "holdGoWay.cpp"

void Peon::activeProg()
{
  if (!this->wayTakts &&
      this->wayIndex <= 5 &&
      this->isPotentialWayComplite &&
      this->orderOnWay->isComplite &&
      !this->gettingTarget)
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
        console.log("get target");
      }
    }
  }

  this->orderOnWayControl();
  if (this->gettingTarget)
  {
    // if (this->gettingTarget->name == "shaht" &&
    //     this->gold <= 0)
    // {
    //   this->cell->groundUnit = nullptr;
    //   this->cell = nullptr;
    //     }
    
  }
  else if (!this->gettingTarget)
  {
    this->goWay();
  }
}