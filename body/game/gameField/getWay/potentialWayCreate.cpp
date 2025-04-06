#include "getPotentialWay.cpp"

void GameField::potentialWayCreate(ProtoObj *unit, ProtoObj *finalCell)
{
    if (unit->cell &&
        unit->cell != finalCell)
    {
        ProtoObj *nextCell = finalCell;
        unit->potentialWay.push(nextCell);
        int large = 0;
        while (true)
        {
            if (nextCell->wayFather &&
                nextCell->wayFather != unit->cell)
            {
                nextCell = nextCell->wayFather;
                unit->potentialWay.push(nextCell);
              //  large += this->get_G(nextCell, nextCell->wayFather);
                // console.log("process");
            }
            else
            {
                //  console.log("fin");
              //  unit->isPotentialWayComplite = true;
                break;
            }
        }
       // console.log("large = " + to_string(large));
    }
      unit->isPotentialWayComplite = true;
}