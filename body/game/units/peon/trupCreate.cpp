#include "updateCurrentTarget.cpp"

void Peon::trupCreate() {
  // console.log(to_string(this->deleteTimer));
   this->deleteTimer--;
   if (this->deleteTimer == 950) {
      this->cell->groundUnit = nullptr;
      console.log("no cell unit");
   }
};