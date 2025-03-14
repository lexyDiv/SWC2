#include "UnitMenu.cpp"

struct UnitMenuPack {
    UnitMenuPack(){
        this->shaht->createShaht();
    }
    ~UnitMenuPack() {
        delete shaht;
        shaht = nullptr;
    std::cout<<"unitMenuShaht DELETE"<<std::endl;
    };
    ProtoUnitMenu *shaht = new UnitMenu;
};


UnitMenuPack unitMenuPack;