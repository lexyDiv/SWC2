//#include "../game/preDraw.cpp"
#include "../fraction/Fraction.cpp"

class Mount : public ProtoObj {

public:
  Mount() : ProtoObj(){};
  ~Mount();
  void create(ProtoObj * cell) override;
  void draw() override;

};