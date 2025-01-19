#include "getVectorCells.cpp"

void GameField::create()
{
    Array<string> array = readMap(&this->path);
    this->width = array.length * this->cellSize;
    this->gabarit = array.getItem(0).size();
    this->height = this->gabarit * this->cellSize;

/////////////////////////////////
    string shahtData = array.getItem(array.length - 1);
    string goldDtataItem = "";
    this->goldData.push(goldDtataItem);
    int goldIndex = 0;
    for (int i = 0; i < shahtData.length(); i++) {
      string lit{shahtData[i]};
      if (lit == ",") {
         goldIndex ++;
         string gdi = "";
         this->goldData.push(gdi);
      } else {
         string &str = this->goldData.getItem3(goldIndex);
         str += lit;
      }
    }

   //  this->goldData.forEach([](string str){
   //    console.log(str);
   //  });


   //  string hz = "100";
   //  int hz2 = stoi(hz);
   //  console.log(to_string(hz2));
///////////////////////////////

    this->mcs = this->miniMapGab / this->gabarit;
    this->miniMapWinGab = ceil(this->mcs * 15);

    this->mapInit(array);
    this->getFieldImage();
    this->getAroundCells(1, false, [](ProtoObj *focusCell, ProtoObj *pushedCell){
       focusCell->aroundCells.push(pushedCell);
    });
    this->getAroundCells(8, true, [](ProtoObj *focusCell, ProtoObj *pushedCell){
       focusCell->drawCells.push(pushedCell);
    });
    this->getAroundCells(11, false, [](ProtoObj *focusCell, ProtoObj *pushedCell){
       focusCell->maxAroundCells.push(pushedCell);
    });
    this->getContinents();

    this->getMaxAroundCellsDis();
    this->getToOtherPlaneCellsNumber();
    this->getToTreeCellLineNumber();
    this->getCellImageCellDrawIndexCellUnitInit();
   //  this->field.getItem(0).getItem(0)->maxAroundCellsDis.forEach([](double dis){
   //    console.log(to_string(dis));
   //  });
    this->init = true;
};