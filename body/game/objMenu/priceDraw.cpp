#include "default.cpp"

void ObjMenu::priceDraw()
{
    Button *fb = buttonsBar.focusButton;
    if (fb &&
        fb->buttonData &&
        fb->buttonData->priceType.length())
    {
        if (fb->buttonData->priceType == "res")
        {
            string one = fb->buttonData->goldPriceInfo(this->unit);
            string too = fb->buttonData->woodPriceInfo(this->unit);
            string three = fb->buttonData->oilPriceInfo(this->unit);

            int lineOneY = 705;
            int lineTooY = 725;
            int lineThreeY = 745;

            int lineOneX = 750;
            int lineTooX = 750;

            Image* imageLineOne = fb->buttonData->isGoldOk(this->unit) ? imager.yes : imager.no;
            Image* imageLineToo = fb->buttonData->isWoodOk(this->unit) ? imager.yes : imager.no;
            Image* imageLineThree = fb->buttonData->isOilOk(this->unit) ? imager.yes : imager.no;

           // Image *lineOneRes = 
           // line One
            ctx.DrawImage(imageLineOne, 0, 0, 256, 256, lineOneX, lineOneY - 2, 16, 16);
            menuText.draw("Gold", lineOneX + 20, lineOneY, 12, 255, 255, 0);
            ctx.DrawImage(imager.goldIcon, 0, 0, 360, 360, lineOneX + 60, lineOneY - 2, 16, 16);
            menuText.draw(one, lineOneX + 100, lineOneY, 12, 255, 255, 0);

            // line Too
            ctx.DrawImage(imageLineToo, 0, 0, 256, 256, lineOneX, lineTooY - 2, 16, 16);
            menuText.draw("Wood", lineOneX + 20, lineTooY, 12, 255, 255, 0);
            ctx.DrawImage(imager.woodIcon, 0, 0, 360, 360, lineOneX + 60, lineTooY - 2, 16, 16);
            menuText.draw(too, lineOneX + 100, lineTooY, 12, 255, 255, 0);

            // line Three
            ctx.DrawImage(imageLineThree, 0, 0, 256, 256, lineOneX, lineThreeY - 2, 16, 16);
            menuText.draw("Oil", lineOneX + 20, lineThreeY, 12, 255, 255, 0);
            ctx.DrawImage(imager.oilIcon, 0, 0, 626, 626, lineOneX + 60, lineThreeY - 2, 16, 16);
            menuText.draw(three, 750 + 100, lineThreeY, 12, 255, 255, 0);
        } else {

            string too = fb->buttonData->manaPriceInfo(this->unit);

            int lineTooY = 725;

            int lineOneX = 750;

         Image* imageLineToo = fb->buttonData->isManaOk(this->unit) ? imager.yes : imager.no;

            // line Too
            ctx.DrawImage(imageLineToo, 0, 0, 256, 256, lineOneX, lineTooY - 2, 16, 16);
            menuText.draw("Mana", lineOneX + 20, lineTooY, 12, 255, 255, 0);
            ctx.DrawImage(imager.icons, 346, 416, 50, 37, lineOneX + 60, lineTooY - 2, 16, 16);
            menuText.draw(too, lineOneX + 100, lineTooY, 12, 255, 255, 0);

        }
    }
}