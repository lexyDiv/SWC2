#include "getCurrentTargetCell.cpp"

void Peon::activeProg()
{

  if (this->orderOnWay && !this->orderOnWay->isComplite)
  {
    ProtoObj *oCell = this->orderOnWay->cell;
    if (!this->cell ||
        (oCell->plane != this->cell->plane) ||
        (oCell->groundUnit == this))
    {

      this->orderOnWay->isComplite = true;
      return;
    }

    // this->ordersOnWayCurrent++;

    if (this->isPotentialWayComplite)
    {
      this->getHandTarget(oCell);

      this->orderOnWay->isComplite = true;
    }
  }

  //////

  if (this->potentialWay.length && this->isPotentialWayComplite)
  {
    if (this->isGetMyCell && this->wayIndex)
    {

      nextMove = false;
      // this->isGetMyCell = false;
      this->wayIndex--;
      // console.log("wayIndex = " + to_string(this->wayIndex));
      this->cell->groundUnit = nullptr;
      this->cell = this->potentialWay.getItem(this->wayIndex);
      this->cell->groundUnit = this;
      /////////////
      this->x = this->cell->x;
      this->y = this->cell->y;
      this->drawIndexY = this->y;
      if (!this->wayIndex)
      {
        this->potentialWay.clear();
      }
    }
  }
}