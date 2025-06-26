#include "getPotentialWay.cpp"

void GameField::potentialWayCreate(ProtoObj *unit, ProtoObj *finalCell)
{
    ProtoObj *uc = unit->cell;
    if (uc &&
        uc != finalCell)
    {
        ProtoObj *nextCell = finalCell;
        unit->pw.push(nextCell);
        int large = 0;
        while (true)
        {
            if (nextCell->wayFather &&
                nextCell->wayFather != uc)
            {
                nextCell = nextCell->wayFather;
                unit->pw.push(nextCell);
            }
            else
            {
                unit->isPotentialWayComplite = true;
                break;
            }
        }
    }

      unit->wayIndex = unit->pw.length;
      unit->isPotentialWayComplite = true;
}