//#include "../game/preDraw.cpp"
#include "../tree/create.cpp"

class Mount : public ProtoObj {

public:
  Mount() : ProtoObj(){};
  ~Mount();
  void create(ProtoObj * cell) override;
  void draw() override;
  bool isIValideOnWay(ProtoObj *unit) override;
};