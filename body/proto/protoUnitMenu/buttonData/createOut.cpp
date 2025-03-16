#include "ButtonData.h"

void ButtonData::createOut() {
    this->infoString = [](ProtoObj* unit){
        return "Menu out";
    };
};