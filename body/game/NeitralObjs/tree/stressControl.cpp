#include "Tree.cpp"

void Tree::stressControl() {
    this->x = this->saveX;
    if (this->stress) {
        if (stress % 2 == 0) {
            this->x += this->stress;
        } else {
            this->x -= this->stress;
        }
            this->stress --;
    }
}