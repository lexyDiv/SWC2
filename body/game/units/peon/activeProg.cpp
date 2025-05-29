#include "holdGoWay.cpp"

void Peon::activeProg()
{
  if (!this->wayTakts &&
  this->wayIndex <= 5 &&
  this->isPotentialWayComplite &&
  this->orderOnWay->isComplite)
  {

   // targetObj validation & get Target//
   if (this->targetObj.unit) {
    this->targetObj.unit->isBlockedd(this);
   }


    if (!this->isIgetMyTarget)
    {
      this->isGetTarget(); 
    }

    if (this->isIgetMyTarget)
    {
      this->targetCell = nullptr;
      this->preTargetCell = nullptr;
      this->stendOnCell();
      console.log("get target");
      this->isIgetMyTarget = false; // !!!
    }
  }

  this->orderOnWayControl();
  this->goWay();
}