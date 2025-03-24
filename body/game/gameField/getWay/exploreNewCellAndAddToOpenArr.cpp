#include "getPotentialWay.cpp"

void GameField::exploreNewCellAndAddToOpenArr(ProtoObj *unit, ProtoObj *cell, ProtoObj *potentialCell)
{
        // cell->F = 0;
        // cell->G = 0;
        // cell->H = 0;
        // cell->createCountData = this->createCount;
        // this->openArr.push(cell);
        // console.log(to_string(this->openArr.length));
        if (cell && unit->isNewCellOnGetWayValide(potentialCell))
        {
                ProtoObj *pc = potentialCell;
                potentialCell->wayFather = cell;
                int G = cell->top == pc ||
                                cell->left == pc ||
                                cell->right == pc ||
                                cell->bottom == pc
                            ? 10
                            : 14;
        }
}