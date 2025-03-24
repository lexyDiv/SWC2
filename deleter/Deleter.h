#include "../body/proto/protoObj/MenuText.cpp"

class Order;

class Deleter {
    public:
    Deleter();
    ~Deleter();
   
   Array<Order *> orders;
   Array<ProtoObj *> objects;

   void process();

};