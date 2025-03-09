#include "UnitMenu.h"

UnitMenu::~UnitMenu()
{

  this->buttonsData.forEach([](Array<ButtonData*> line){
    line.forEach([](ButtonData* bd){
      delete bd;
      bd = nullptr;
    //  std::cout << "BUTTON DATA DELETED !!!!!!!!!!!" << std::endl;
    });
  });
}
