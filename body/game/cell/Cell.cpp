#include "Cell.h"



Cell::~Cell()
{
   //std::cout << "cell deleted" << std::endl;
   this->waters.forEach([](Water* water){
    delete water;
    water = nullptr;
   });
   if (this->groundUnit != nullptr) {
    delete this->groundUnit;
    this->groundUnit = nullptr;
   }
}


Color Cell::getMapColor()
{
    return this->mapColor;
};
