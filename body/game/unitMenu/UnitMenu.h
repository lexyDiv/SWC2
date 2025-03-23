#include "../fraction/create.cpp"


class UnitMenu : public ProtoUnitMenu {
    public:
    UnitMenu() : ProtoUnitMenu(){};
    ~UnitMenu();

    void createOil();

    void create() override;
    void createShaht() override;



};