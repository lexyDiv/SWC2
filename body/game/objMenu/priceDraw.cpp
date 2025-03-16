#include "default.cpp"

void ObjMenu::priceDraw()
{
    if (buttonsBar.focusButton &&
        buttonsBar.focusButton->buttonData &&
        buttonsBar.focusButton->buttonData->priceType.length())
    {
        if (buttonsBar.focusButton->buttonData->priceType == "res")
        {
            string one = "papa";
            string too = "super";
            string three = "loh";

            int y = 705;

            menuText.draw(one, 750, y, 12, 255, 255, 0);
            menuText.draw(too, 750, y + 20, 12, 255, 255, 0);
            menuText.draw(three, 750, y + 40, 12, 255, 255, 0);
        }
    }
}