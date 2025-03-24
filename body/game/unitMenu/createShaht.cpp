#include "createPeon.cpp"

void UnitMenu::createShaht()
{
    this->getTitleName = [](ProtoObj *unit)
    {
        return "Gold mine";
    };

    for (int i = 0; i < 5; i++)
    {
        Lambda lambda;
        this->infoLines.push(lambda);
    }

    this->infoLines.getItem3(2).fn = [](ProtoObj *unit)
    {
        return "Gold: " + to_string(unit->gold);
    };

    this->titleMenuXY = [](ProtoObj *unit){
        Point point = {x: 200, y: 290};
        return point;
    };

    // this->getIsUpgrade = [](ProtoObj* unit){
    //   return false;
    // };

    // this->upgrade = [](ProtoObj* unit){
    //   UpgradeData ud;
    //   ud.image = imager.icons;
    //   ud.compliteCount = 1000;
    //   ud.currentCount = 500;
    //   ud.animX = 200;
    //   ud.animY = 290;
    //   ud.animWidth = 50;
    //   ud.animHeight = 42;
    //   return ud;
    // };

    // this->getIsHp = [](ProtoObj* unit){
    //   return false;
    // };
    //   this->getIsMana = [](ProtoObj* unit){
    //   return false;
    // };
/////////////////////////////// buttons data

this->isButtons = true;

   Array<Array<ButtonData *>> slice;
  for (int ver = 0; ver < 4; ver++)
  {
    Array<ButtonData *> line;
    for (int hor = 0; hor < 5; hor++)
    {
      ButtonData *buttonData = buttonDataHub.voidButtonData;
      line.push(buttonData);
    };
    slice.push(line);
  };
  this->buttonsData.push(slice);

  this->buttonsData.getItem3(0).getItem3(3).changeEl(buttonDataHub.outButtonData, 4);

};