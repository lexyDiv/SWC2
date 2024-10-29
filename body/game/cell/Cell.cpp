#include "Cell.h"

Cell::~Cell()
{
   // std::cout << "cell deleted" << std::endl;
}


Color Cell::getMapColor()
{
    return this->mapColor;
    // if (this->type == "ground") {
    //     return {R: 255, G: 255, B: 255};
    // } else if (this->type == "water") {
    //     return {R: 0, G: 0, B: 0};
    // }
    // return {R: 100, G: 100, B: 100};
};
