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
    int titleNameFontSize = 22;
    int fontSize = 12;
    string titleName = unit->unitMenu->getTitleName(unit);
    int titleNameGabX = titleName.size() * (titleNameFontSize * 0.7);
    int titleNameX = objMenu->centerX - titleNameGabX / 2;
    menuText.draw(titleName, titleNameX, this->y + 15, titleNameFontSize, 255, 255, 255);

    ctx.DrawImage(imager.icons,
                  unit->unitMenu->titleMenuX,
                  unit->unitMenu->titleMenuY,
                  50,
                  42,
                  this->x,
                  this->y + 50,
                  this->gabX,
                  this->gabY);

    ctx.StrokeRect(this->x, this->y + 50, this->gabX, this->gabY, 110, 110, 110);
    int infoLineX = this->x + 110;
    int infoLineY = this->y + 54;
    unit->unitMenu->infoLines.forEach([unit, this, fontSize, infoLineX, infoLineY](Lambda lambda, int i)
                                      {
      string resStr = lambda.fn(unit);
      menuText.draw(resStr, infoLineX, infoLineY + (i * 20), fontSize, 255, 255, 0); });

    if (unit->unitMenu->getIsHp(unit))
    {
      int y = this->y + 178;
      string resHp = "Hit points: " + to_string(unit->hp) + " / " + to_string(unit->hpMax);
      titleNameGabX = resHp.size() * (fontSize * 0.7);
      titleNameX = objMenu->centerX - titleNameGabX / 2;
      int width = (unit->hp * 250) / unit->hpMax;
      string color = width >= 166 ? "green" : width >= 83 ? "yellow"
                                                          : "red";
      ctx.FillRect(750, y, width, 10, color);
      ctx.StrokeRect(750, y, 250, 10, 110, 110, 110);
      menuText.draw(resHp, titleNameX, y - 15, fontSize, 255, 255, 0);
    }
    if (unit->unitMenu->getIsMana(unit))
    {
      int y = this->y + 208;
      string resHp = "Hit points: " + to_string(unit->hp) + " / " + to_string(unit->hpMax);
      titleNameGabX = resHp.size() * (fontSize * 0.7);
      titleNameX = objMenu->centerX - titleNameGabX / 2;
      int width = (unit->hp * 250) / unit->hpMax;
      string color = width >= 166 ? "green" : width >= 83 ? "yellow"
                                                          : "red";
      ctx.FillRect(750, y, width, 10, color);
      ctx.StrokeRect(750, y, 250, 10, 110, 110, 110);
      menuText.draw(resHp, titleNameX, y - 15, fontSize, 255, 255, 0);
    }
  };
}
