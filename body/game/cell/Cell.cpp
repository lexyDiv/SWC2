#include "Cell.h"



Cell::~Cell()
{
   // std::cout << "cell deleted" << std::endl;
}


Color Cell::getMapColor()
{
    return this->mapColor;
};
