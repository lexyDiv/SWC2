#include "getHandTarget.cpp"

// bool Peon::isOnGetPotentialWayGetTarget(ProtoObj *cell)
// {
//     ProtoObj *tc = this->targetCell;
//     if (tc->groundUnit)
//     {
//         if (cell->groundUnit && tc->groundUnit == cell->groundUnit)
//         {
//             return true;
//         }
//         else if (this->profession == "lesorub")
//         {
//             Array<ProtoObj *> potentialFinishCells;
//             for (int i = 0; i < cell->aroundCells.length; i++)
//             {
//                 ProtoObj *ac = cell->aroundCells.getItem(i);
//                 if (ac->groundUnit && ac->groundUnit->name == "tree")
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     else if (tc == cell)
//     {
//         return true;
//     }
//     return false;
// };