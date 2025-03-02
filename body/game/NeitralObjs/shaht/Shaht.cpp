#include "Shaht.h"

Shaht::~Shaht()
{
    std::cout<<"shaht DELETE"<<std::endl;
    this->interUnits.forEach([](ProtoObj* peon){
        delete peon;
        peon = nullptr;
    });

    if (this->unitMenu) {
        delete this->unitMenu;
        this->unitMenu = nullptr;
    }
}
