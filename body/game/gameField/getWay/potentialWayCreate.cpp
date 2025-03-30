#include "getPotentialWay.cpp"

void GameField::potentialWayCreate(ProtoObj *unit, ProtoObj *finalCell)
{
    if (unit->cell &&
        unit->cell != finalCell)
    {
        ProtoObj *nextCell = finalCell;
        unit->potentialWay.push(nextCell);
        while (true)
        {
            if (nextCell->wayFather &&
                nextCell->wayFather != unit->cell)
            {
                nextCell = nextCell->wayFather;
                unit->potentialWay.push(nextCell);
                // console.log("process");
            }
            else
            {
                //  console.log("fin");
                unit->isPotentialWayComplite = true;
                break;
            }
        }
    }
    //  unit->isPotentialWayComplite = true;
}