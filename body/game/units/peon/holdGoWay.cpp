#include "stendOnCellWait.cpp"

bool Peon::isNeedHoldGoWay(ProtoObj *nextCell)
{
    ProtoObj *gu = nextCell->groundUnit;
    if (gu &&
        gu->type == "life")
    {
        ProtoObj *guNextCell = gu->isPotentialWayComplite &&
                                       gu->potentialWay.length &&
                                       gu->wayIndex - 1
                                   ? gu->potentialWay.getItem(gu->wayIndex - 1) // ??
                                   : nullptr;
        // ProtoObj *nextNextCell = this->wayIndex > 2
        //                              ? this->potentialWay.getItem(this->wayIndex - 2)
        //                              : nullptr;
        if (!gu->isPotentialWayComplite ||
            (guNextCell && guNextCell != this->cell))
        {
            return true;
        }
    }
    return false;
};