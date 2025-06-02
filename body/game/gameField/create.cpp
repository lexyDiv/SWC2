#include "getWay/exploreNewCellAndAddToOpenArr.cpp"


void GameField::create()
{
    Array<string> array = readMap(&this->path);
    console.log(to_string(array.length));
    /////////////////////////
   //  json j;
   //  j["name"] = "test_bigest_500";
   //  j["oil"].push_back(100);
   //  j["oil"].push_back(200);
   //  j["gold"].push_back(10000);
   //  j["gold"].push_back(20000);
   //  array.forEach([&j](string line){
   //    j["field"].push_back(line);
   //  });
   //  string sPath = "strings/test_bigest_500.txt";
   //  writeStr(&sPath, to_string(j));
    ///////////////////////////
   // this->width = array.length * this->cellSize;
  // console.log(to_string(this->cellSize));
   //  double d = sqrt(48 * 48 + 48 * 48);
   //  console.log(to_string(d));
    this->gabarit = array.getItem(0).size();
    this->height = this->gabarit * this->cellSize;
    this->width = this->height;


///////////////////////////////// get oil data
    string oilData = array.getItem(array.length - 1);
    string oilDtataItem = "";
    this->oilData.push(oilDtataItem);
    int oilIndex = 0;
    for (int i = 0; i < oilData.length(); i++) {
      string lit{oilData[i]};
      if (lit == ",") {
         oilIndex ++;
         string odi = "";
         this->oilData.push(odi);
      } else {
         string &str = this->oilData.getItem3(oilIndex);
         str += lit;
      }
    }
   array.pop();

///////////////////////////////

///////////////////////////////// get gold data
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
   array.pop();

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