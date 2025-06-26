#include "../fraction/create.cpp"


class UnitMenu : public ProtoUnitMenu {
    public:
    UnitMenu() : ProtoUnitMenu(){};
    ~UnitMenu();

    void createOil() override;

    void create() override;
    void createShaht() override;
    void createPeon() override;


};