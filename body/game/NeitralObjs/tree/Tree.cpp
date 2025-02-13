#include "Tree.h"

Tree::~Tree()
{
   // std::cout<<"tree DELETE"<<std::endl;
       if (this->unitMenu) {
        delete this->unitMenu;
        this->unitMenu = nullptr;
    }
}
