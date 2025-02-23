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
       string titleName = unit->unitMenu->getTitleName(unit);
       int titleNameGabX = titleName.size() * (titleNameFontSize * 0.7);
       int titleNameX = objMenu->centerX - titleNameGabX / 2;
       menuText.draw(titleName, titleNameX, 250, titleNameFontSize, 255, 255, 255);
        ctx.DrawImage(imager.icons, unit->unitMenu->titleMenuX, unit->unitMenu->titleMenuY, 50, 42, this->x, this->y, this->gabX, this->gabY);
        string resStr = unit->unitMenu->getTitl_1_line(unit);
           menuText.draw(resStr, 840, 300, 15, 255, 255, 0);
           resStr = unit->unitMenu->getTitl_2_line(unit);
           menuText.draw(resStr, 840, 322, 15, 255, 255, 0);
           resStr = unit->unitMenu->getTitl_3_line(unit);
           menuText.draw(resStr, 840, 344, 15, 255, 255, 0);

        // if (unit->unitMenu->resurs) {
        //   int resurs;
        //   string resursName = "";
        //   if (unit->gold >= 0) {
        //     resurs = unit->gold;
        //     resursName = "Gold";
        //   } else {
        //     resurs = unit->oil;
        //     resursName = "Oil";
        //   }
        //   string resStr = resursName + ": " + to_string(resurs);
        //   menuText.draw(resStr, 840, 295, 15, 255, 255, 0);
        //   menuText.draw(resStr, 840, 325, 15, 255, 255, 0);
        //   menuText.draw(resStr, 840, 355, 15, 255, 255, 0);
         
        // }
    };
}
