#include "Oil.h"

Oil::~Oil()
{
    this->lines.forEach([](AnimLines *line)
                        {
        delete line;
        line = nullptr; });
    if (this->unitMenu)
    {
        delete this->unitMenu;
        this->unitMenu = nullptr;
    }
}
