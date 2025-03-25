#include "get_H.cpp"

int GameField::get_G(ProtoObj *cell, ProtoObj *potentialCell)
{
    ProtoObj *pc = potentialCell;
    return cell->top == pc ||
                   cell->left == pc ||
                   cell->right == pc ||
                   cell->bottom == pc
               ? 10
               : 14;
}