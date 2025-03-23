#include "unitMenuPack.h"

void UnitMenu::createPeon() {
        this->getTitleName = [](ProtoObj *unit)
    {
        return "Peon";
    };

    for (int i = 0; i < 5; i++)
    {
         Lambda lambda;
        switch (i)
        {

        case 0:
            lambda.fn = [](ProtoObj* unit){
                return "Level:  " + to_string(unit->getLevel());
            };
            break;

        case 1:
            lambda.fn = [](ProtoObj* unit){
                return "Attack: " + to_string(unit->attack);
            };
            break;

        case 2:
            lambda.fn = [](ProtoObj* unit){
                return "Armor:  " + to_string(unit->armor);
            };
            break;

        case 3:
            lambda.fn = [](ProtoObj* unit){
                return "Speed:  " + to_string(unit->speed);
            };
            break;

        case 4:
            lambda.fn = [](ProtoObj* unit){
                return "Sight:  " + to_string(unit->sight);
            };
            break;
            
        
        default:
            break;
        }
        this->infoLines.push(lambda);
    }


    this->titleMenuXY = [](ProtoObj *unit){
        Point point = {x: 53, y: 3};
        return point;
    };

    this->getIsHp = [](ProtoObj* unit){
        return true;
    };
};