

class Deleter {
    public:
    Deleter();
    ~Deleter();
   
   Array<Order *> orders;
   Array<ProtoObj *> objects;

   void process();

};