#include "stendOnCellWait.cpp"

bool Peon::isNeedHoldGoWay(ProtoObj *nextCell)
{
    ProtoObj *gu = nextCell->groundUnit;
    if (gu &&
        gu->type == "life")
    {
        ProtoObj *guNextCell = gu->isPotentialWayComplite &&
                                       gu->potentialWay.length &&
                                       gu->wayIndex
                                   ? gu->potentialWay.getItem(gu->wayIndex - 1) // ??
                                   : nullptr;

        if (!gu->isPotentialWayComplite ||
            (guNextCell && guNextCell != this->cell))
        {
            return true;
        }
    }

    bool isCrox = (nextCell == this->cell->top_right 
                  && ((this->cell->top->groundUnit &&
                     !this->cell->top->groundUnit->isGetMyCell && this->cell->top->groundUnit->conor == this->unitMenu->conorTop_left) ||
                    (this->cell->right->groundUnit &&
                     !this->cell->right->groundUnit->isGetMyCell &&
                     this->cell->right->groundUnit->conor == this->unitMenu->conorBottom_right))
                     ) ||
                          // 2
                          (nextCell == this->cell->top_left 
                          && ((this->cell->top->groundUnit &&
                             !this->cell->top->groundUnit->isGetMyCell &&
                             this->cell->top->groundUnit->conor == this->unitMenu->conorTop_right) ||
                            (this->cell->left->groundUnit &&
                             !this->cell->left->groundUnit->isGetMyCell &&
                             this->cell->left->groundUnit->conor == this->unitMenu->conorBottom_left))
                             ) ||
                          // 3
                          (nextCell == this->cell->bottom_left 
                          && ((this->cell->left->groundUnit &&
                             !this->cell->left->groundUnit->isGetMyCell &&
                             this->cell->left->groundUnit->conor == this->unitMenu->conorTop_left) ||
                            (this->cell->bottom->groundUnit &&
                             !this->cell->bottom->groundUnit->isGetMyCell &&
                             this->cell->bottom->groundUnit->conor == this->unitMenu->conorBottom_right))
                             ) ||

                          // 4
                          (nextCell == this->cell->bottom_right 
                          && ((this->cell->bottom->groundUnit &&
                             !this->cell->bottom->groundUnit->isGetMyCell &&
                             this->cell->bottom->groundUnit->conor == this->unitMenu->conorBottom_left) ||
                            (this->cell->right->groundUnit &&
                             !this->cell->right->groundUnit->isGetMyCell &&
                             this->cell->right->groundUnit->conor == this->unitMenu->conorTop_right))
                             )
                      ? true
                      : false;

    if (isCrox)
    {
        return true;
    }

    return false;
};