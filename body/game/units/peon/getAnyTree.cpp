#include "isOnGetPotentialWayGetTarget.cpp"

void Peon::getAnyTree()
{
  ProtoObj *base = this->getBaseForUnloading();
  if (base) {
    console.log("logic for scan optimal tree");
  } else {
    console.log("logic without base optimal tree");
  }
}