#include "ProtoObjMenu.h"

ProtoObjMenu::ProtoObjMenu()
{
}

ProtoObjMenu::~ProtoObjMenu()
{
}

void ProtoObjMenu::create(ProtoGameField* gf)
{
    
}

void ProtoObjMenu::getCandidateCells()
{
}

void ProtoObjMenu::control()
{
}

void ProtoObjMenu::draw()
{
}

void TitleUnit::draw(ProtoObj *unit, ProtoObjMenu *objMenu)
{
    {
      
       // ctx.DrawText(750, 250, 20, unit->unitMenu->titleName);
       int titleNameFontSize = 20;
       string titleName = unit->unitMenu->titleName;
       int titleNameGabX = titleName.size() * (titleNameFontSize * 0.7);
       int titleNameX = objMenu->centerX - titleNameGabX / 2;
       menuText.draw(titleName, titleNameX, 250, titleNameFontSize);
        ctx.DrawImage(imager.icons, unit->unitMenu->titleMenuX, unit->unitMenu->titleMenuY, 50, 42, this->x, this->y, this->gabX, this->gabY);
        if (unit->unitMenu->resurs) {
          int resurs;
          string resursName = "";
          if (unit->gold >= 0) {
            resurs = unit->gold;
            resursName = "Gold";
          } else {
            resurs = unit->oil;
            resursName = "Oil";
          }
          string resStr = resursName + ": " + to_string(resurs);
          menuText.draw(resStr, 750, 400, 15);
         // ctx.DrawText(750, 400, 20, resStr);
        }
    };
}
