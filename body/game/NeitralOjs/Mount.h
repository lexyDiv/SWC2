#include "../game/preDraw.cpp"

class Mount : public ProtoObj {

public:
  Mount() : ProtoObj(){};
  ~Mount();
  void create(ProtoObj * cell) override;

};