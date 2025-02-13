#include "../fraction/create.cpp"

class UnitMenu : public ProtoUnitMenu {
    public:
    UnitMenu() : ProtoUnitMenu(){};
    ~UnitMenu();
    void create(ProtoObj* unit) override;
};