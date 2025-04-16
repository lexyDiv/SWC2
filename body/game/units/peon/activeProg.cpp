#include "getCurrentTargetCell.cpp"

void Peon::activeProg()
{
  // console.log("here");
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

    if (this->isPotentialWayComplite)
    {
      this->getHandTarget(oCell);

      this->orderOnWay->isComplite = true;
    }
  }

  ////// go way
  ProtoObj *nextCell = this->potentialWay.length ? this->potentialWay.getItem(this->wayIndex - 1) : nullptr;
  if (nextCell)
  {
    if (
        this->potentialWay.length &&
        this->isPotentialWayComplite &&
        this->isGetMyCell &&
        (!nextCell->groundUnit))
    {
      // this->cell->groundUnit = nullptr;
      // nextCell->groundUnit = this;
      this->isGetMyCell = false;
      // this->wayIndex--;
      this->wayTakts = 0;
       console.log("here 1");
    }

    if (!this->isGetMyCell)
    {
      if (!this->wayTakts)
      {
         console.log("here 2");
         this->cell->groundUnit = nullptr;
         this->cell = nextCell;
         this->cell->groundUnit = this;
      }
    }
  }
  else if (this->wayTakts)
  {
    console.log("here 3");
  }
  else
  {
    console.log("here 4");
    this->stendOnCell();
  }

  // if (
  //     this->potentialWay.length &&
  //     this->isPotentialWayComplite &&
  //     this->wayIndex &&
  //     !this->wayTakts)
  // {
  //   ProtoObj *nextCell = this->potentialWay.getItem(this->wayIndex - 1);

  //   if (!nextCell->groundUnit)
  //   {
  //     // console.log("here");
  //     // this->speedTaleStart = 1;

  //     this->wayIndex--;
  //     this->x = this->cell->x;
  //     this->y = this->cell->y;
  //     double saveSpeedTale = this->speedTale;
  //     this->unitMenu->getDeltasXY(this, nextCell);
  //     this->cell->groundUnit = nullptr;
  //     this->cell = nextCell;
  //     this->cell->groundUnit = this;
  //     this->x += cos(this->conor) * this->speedTale;
  //     this->y += sin(this->conor) * this->speedTale;
  //     this->drawIndexY = this->y;
  //     this->isGetMyCell = false;
  //   }
  //   else
  //   {
  //     this->stendOnCell();
  //   }
  // }

  // if (this->wayTakts)
  // {
  //   this->x += this->wayDeltaX;
  //   this->y += this->wayDeltaY;
  //   this->drawIndexY = this->y;
  //   this->wayTakts--;
  //   this->isGetMyCell = false;
  //   this->animTimer++;
  //   // if (this->animTimer == 100)
  //   // {
  //   //   this->animTimer = 1;
  //   // }
  //   // if (this->animTimer % 8 == 0)
  //   // {
  //   //   // console.log(to_string(this->animY));
  //   //   this->animY += this->animGabY;
  //   //   if (this->animY == this->animGabY * 5)
  //   //   {
  //   //     this->animY = this->animGabY;
  //   //   }
  //   // }
  // }
  // // else if (!this->isGetMyCell)
  // // {
  // //     this->stendOnCell();
  // // }
}