#include "Cell.h"



Cell::~Cell()
{
   //std::cout << "cell deleted" << std::endl;
   this->waters.forEach([](Water* water){
    delete water;
    water = nullptr;
   });
   if (this->groundUnit != nullptr && !this->groundUnit->isDelete) {
    this->groundUnit->isDelete = true;
    delete this->groundUnit;
    this->groundUnit = nullptr;
   }
}


Color Cell::getMapColor()
{
    if (this->groundUnit) {
        return this->groundUnit->mapColor;
    }
    return this->mapColor;
};
