#include "Oil.cpp"

void Oil::create(ProtoObj *cell)
{
    this->createUnitMenu();
    /////////////////////////////
    this->get2x2myCells(cell);
    ProtoObj *exitCell = cell->left;
    ProtoObj *centerCell = cell->bottom_right;
    this->cell = centerCell;
    this->cell->game->AllUnits.push(this);

    this->getContactAndExitCells(cell, exitCell, centerCell);

    this->name = "oil";
    this->type = "building";
    this->mapColor = {R : 0, G : 0, B : 0};
    this->image = imager.oilPoint;
    this->x = cell->x;
    this->y = cell->y;
    this->getGabX = cell->gabX * 2;
    this->getGabY = this->getGabX;
    this->drawIndexY = cell->y - 100;
    this->hpMax = 1000;
    this->hp = 1000;

    int y = 0;
    int stepY = this->getGabY / this->linesCount;
    //  console.log(to_string(stepY));
    int lineYGab = 100 / this->linesCount;
    for (int i = 0; i < 100; i += lineYGab)
    {
        AnimLines *line = new AnimLines;
        line->gabY = stepY + 1;
        line->y = y;
        line->animY = i;
        line->animGabY = lineYGab;
        y += stepY + 1;
        this->lines.push(line);
    }
    // int dx =
    // this->lines.forEach([](AnimLines* line, int i){
    //    // int pmRand = intRand(0, 2);
    //     // int dxRand = intRand(0, 5);
    //     // line->deltaX = pmRand ? dxRand : -dxRand;
    //     line->p = i % 2 == 0 ? 1 : -1;
    // });

    ////////////

    cell->plane->oils.push(this);
};