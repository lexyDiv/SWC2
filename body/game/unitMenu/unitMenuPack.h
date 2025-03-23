#include "UnitMenu.cpp"

struct UnitMenuPack {
    UnitMenuPack(){
        this->shaht->createShaht();
        this->oil->createOil();
    }
    ~UnitMenuPack() {
        delete this->shaht;
        this->shaht = nullptr;

        delete this->oil;
        this->oil = nullptr;
    std::cout<<"unitMenuShaht DELETE"<<std::endl;
    };
    ProtoUnitMenu *shaht = new UnitMenu;
    UnitMenu *oil = new UnitMenu;
};


UnitMenuPack unitMenuPack;