#include "../buttonData/createOut.cpp"

void Fraction::controller() {
    if (this->control == "human") {
        this->orderControl();
    }
    this->activeUnitsControl();
};