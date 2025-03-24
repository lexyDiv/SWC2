#include "UnitMenu.cpp"

struct UnitMenuPack {
    UnitMenuPack(){
        this->shaht->createShaht();
        this->oil->createOil();
        this->peon->createPeon();
    }
    ~UnitMenuPack() {
        delete this->peon;
        this->peon = nullptr;

        delete this->shaht;
        this->shaht = nullptr;

        delete this->oil;
        this->oil = nullptr;
    std::cout<<"unitMenuShaht DELETE"<<std::endl;
    };
    ProtoUnitMenu *shaht = new UnitMenu;
    ProtoUnitMenu *peon = new UnitMenu;
    UnitMenu *oil = new UnitMenu;
};


UnitMenuPack unitMenuPack;