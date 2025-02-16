#include "ObjMenu.cpp"

void ObjMenu::getCandidateCells()
{
    if (this->zone.active)
    {
       // this->candidateCells.clear();
       this->units.clear();
       this->unit = nullptr;
        int cellSize = this->gf->cellSize;
        this->zone.active = false;
        int firstX = this->zone.a.x;
        int firstY = this->zone.a.y;
        int indexX = ceil(firstX / cellSize);
        int indexY = ceil(firstY / cellSize);
        ProtoObj *fc = this->gf->field.getItem(indexY).getItem(indexX);
        int secX = this->zone.b.x;
        int secY = this->zone.b.y;
        int gabX = secX - fc->x;
        int gabY = secY - fc->y;

        int intX = indexX + ceil((gabX) / cellSize) + 1;
        int intY = indexY + ceil((gabY) / cellSize) + 1;
        if (intX > this->gf->gabarit) {
            intX = 65;
        }
        if (intY > this->gf->gabarit) {
            intY = 65;
        }
         
        Array<ProtoObj *> units;
        ProtoObj * building = nullptr;
        Array<ProtoObj *> ships;
        Array<ProtoObj *> fly;

        for (int ver = indexY; ver < intY; ver++)
        {
            for (int hor = indexX; hor < intX; hor++)
            {
                ProtoObj *unit = this->gf->field.getItem(ver).getItem(hor)->groundUnit;
                if (unit && !unit->inZone && unit->unitMenu)
                {
                    if (unit->fraction &&
                        unit->fraction->control == "human" &&
                        unit->type == "life")
                    {
                        units.push(unit);
                        unit->inZone = true;
                      //  console.log("life");
                    }

                    if (
                        unit->type == "building" &&
                        !building &&
                        (!unit->fraction || unit->fraction->control == "human"))
                    {
                        building = unit;
                        unit->inZone = true;
                       // console.log("building");
                    }
                }
            }
        }
        if (units.length == 1) {
            this->unit = unit;
        } else if (units.length > 1) {
            units.forEach([this](ProtoObj* unit){
                this->units.push(unit);
            });
        } else if (building) {
            building->inZone = false;
            this->unit = building;
        }
        ////////////////////////////////////////
        if (building) {
            building->inZone = false;
        }
        this->units.forEach([](ProtoObj* unit){
            unit->inZone = false;
        });
    };
};