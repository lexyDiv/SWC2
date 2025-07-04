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


void GameField::potentialWayCreate2(ProtoObj *unit, ProtoObj *finalCell)
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
            if (nextCell->wayFather2 &&
                nextCell->wayFather2 != uc)
            {
                nextCell = nextCell->wayFather2;
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