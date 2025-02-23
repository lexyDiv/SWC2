#include "ProtoObjMenu.h"

ProtoObjMenu::ProtoObjMenu()
{
}

ProtoObjMenu::~ProtoObjMenu()
{
}

void ProtoObjMenu::create(ProtoGameField *gf)
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
    int titleNameFontSize = 20;
    string titleName = unit->unitMenu->getTitleName(unit);
    int titleNameGabX = titleName.size() * (titleNameFontSize * 0.7);
    int titleNameX = objMenu->centerX - titleNameGabX / 2;
    menuText.draw(titleName, titleNameX, 250, titleNameFontSize, 255, 255, 255);
    ctx.DrawImage(imager.icons, unit->unitMenu->titleMenuX, unit->unitMenu->titleMenuY, 50, 42, this->x, this->y, this->gabX, this->gabY);
    ctx.StrokeRect(this->x, this->y, this->gabX, this->gabY, 110, 110, 110);
    string resStr = unit->unitMenu->getTitl_1_line(unit);
    menuText.draw(resStr, 840, 284, 15, 255, 255, 0);
    resStr = unit->unitMenu->getTitl_2_line(unit);
    menuText.draw(resStr, 840, 304, 15, 255, 255, 0);
    resStr = unit->unitMenu->getTitl_3_line(unit);
    menuText.draw(resStr, 840, 323, 15, 255, 255, 0);
    resStr = unit->unitMenu->getTitl_4_line(unit);
    menuText.draw(resStr, 840, 342, 15, 255, 255, 0);
    resStr = unit->unitMenu->getTitl_5_line(unit);
    menuText.draw(resStr, 840, 362, 15, 255, 255, 0);
    if (unit->unitMenu->hp) {
      int y = 390;
      string resHp = to_string(unit->hp) + " / " + to_string(unit->hpMax);
      titleNameGabX = resHp.size() * (titleNameFontSize * 0.7);
      titleNameX = objMenu->centerX - titleNameGabX / 2;
      int width = (unit->hp * 250) / unit->hpMax;
      string color = width >= 166 ? "green" : width >= 83 ? "yellow" : "red"; 
      ctx.FillRect(750, y, width, 20, color);
      ctx.StrokeRect(750, y, 250, 20, 110, 110, 110);
      menuText.draw(resHp, titleNameX, y, titleNameFontSize, 255, 255, 255);
    }
  };
}
