#include "draw.cpp"

void ObjMenu::getCandidateCells()
{
    if (this->zone.active)
    {
       this->defaultData();
        int cellSize = this->gf->cellSize;

        int firstX = this->zone.a.x;
        int firstY = this->zone.a.y;
        int indexX = ceil(firstX / cellSize);
        int indexY = ceil(firstY / cellSize);

        ProtoObj *fc = this->gf->field.getItem(indexY).getItem(indexX);
        int secX = this->zone.b.x;
        int secY = this->zone.b.y;
        int gabX = secX - fc->x;
        int gabY = secY - fc->y;

        int zoneWidth = indexX + ceil((gabX) / cellSize) + 1;
        int zoneHeight = indexY + ceil((gabY) / cellSize) + 1;
        int intX = zoneWidth <= this->gf->gabarit ? zoneWidth : this->gf->gabarit;
        int intY = zoneHeight <= this->gf->gabarit ? zoneHeight : this->gf->gabarit;

        Array<ProtoObj *> units;
        ProtoObj *building = nullptr;
        Array<ProtoObj *> ships;
        Array<ProtoObj *> fly;

        Array<ProtoObj *> allUnits;

        for (int ver = indexY; ver < intY; ver++)
        {
            for (int hor = indexX; hor < intX; hor++)
            {
                ProtoObj *unit = this->gf->field.getItem(ver).getItem(hor)->groundUnit;

                if (unit && !unit->inZone && unit->unitMenu)
                {
                  //  console.log(unit->name);
                   unit->inZone = true;
                   allUnits.push(unit);


                    if (unit->fraction &&
                      //  unit->fraction->control == "human" && // chenge here
                        unit->type == "life")
                    {
                        units.push(unit);
                       // unit->inZone = true;
                        //  console.log("life");
                    }

                    if (
                        unit->type == "building" &&
                        !building &&
                        (!unit->fraction || unit->fraction->control == "human"))
                    {
                        building = unit;
                      //  unit->inZone = true;
                        // console.log("building");
                    }
                }
            }
        }


        
        if (units.length == 1)
        {
            this->potencialUnit = units.getItem(0);
            this->potencialUnit->inZone = false;
        }
        else if (units.length > 1)
        {
            units.forEach([this](ProtoObj *unit)
                          { this->potencialUnits.push(unit); });
                         // console.log(to_string(this->potencialUnits.length));
        }
        else if (building)
        {
           // this->defaultData();
            building->inZone = false;
            this->potencialUnit = building;
           // console.log("new state");
        } else {
            // console.log("out");
        }
        ////////////////////////////////////////
        allUnits.forEach([](ProtoObj* unit){
            unit->inZone = false;
        });

    };
};