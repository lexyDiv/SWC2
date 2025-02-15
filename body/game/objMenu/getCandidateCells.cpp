#include "ObjMenu.cpp"

void ObjMenu::getCandidateCells()
{
    if (this->zone.active)
    {
        this->candidateCells.clear();
        int cellSize = this->gf->cellSize;
        this->zone.active = false;
        int firstX = this->zone.a.x;
        int firstY = this->zone.a.y;
        int indexX = ceil(firstX / cellSize);
        int indexY = ceil(firstY / cellSize);
        ProtoObj* fc = this->gf->field.getItem(indexY).getItem(indexX);
        int secX = this->zone.b.x;
        int secY = this->zone.b.y;
        int gabX = secX - fc->x;
        int gabY = secY - fc->y;

        int intX = indexX + ceil((gabX) / cellSize) + 1;
        int intY = indexY + ceil((gabY) / cellSize) + 1;
    //     console.log("------------------------------");
    //     string a = "indexX = " + to_string(indexX);
    //     string b = "intX = " + to_string(intX);
    //     string c = "gabX = " + to_string(gabX);
    //    // console.log(a);
    //    // console.log(b);
    //   //  console.log(c);

        for (int ver = indexY; ver < intY; ver++)
        {
            for (int hor = indexX; hor < intX; hor++)
            {
                ProtoObj *cell = this->gf->field.getItem(ver).getItem(hor);
                this->candidateCells.push(cell);
            }
        }
    };
};