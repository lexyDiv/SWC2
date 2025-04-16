#include "Peon.h"

Peon::Peon()
{
}

Peon::~Peon()
{
    if (this->orderOnWay) {
        delete this->orderOnWay;
        this->orderOnWay = nullptr;
    }
    std::cout<<"PEON DELETED !!!"<<std::endl;
}
