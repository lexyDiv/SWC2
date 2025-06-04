#include "Shaht.cpp"

void Shaht::wellCome(ProtoObj *peon) {
   // console.log("shaht well come !");
    int index = this->contactCells.indexOf(peon->cell);
    ProtoObj *wellComeCell = index != -1 ? this->wellComeCells.getItem(index) : nullptr;
    if (wellComeCell) {
        peon->unitMenu->getConor(peon, wellComeCell);
        
       // console.log("peon have wellcome cell");
    }
   // console.log(to_string(this->contactCells.indexOf(peon->cell)));
};