//#include "../game/preDraw.cpp"
#include "../../proto/protoGame/ProtoGame.cpp"

class Mount : public ProtoObj {

public:
  Mount() : ProtoObj(){};
  ~Mount();
  void create(ProtoObj * cell) override;

};