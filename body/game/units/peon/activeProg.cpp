#include "holdGoWay.cpp"

void Peon::activeProg()
{
  bool isIgetMyTarget = this->isGetTarget();
  if (isIgetMyTarget)
  {
    this->targetCell = nullptr;
    this->preTargetCell = nullptr;
    this->stendOnCell();
  }

  this->orderOnWayControl();
  this->goWay();
}