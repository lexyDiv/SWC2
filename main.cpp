// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "Listenner.h"

bool quit = false;

void hard()
{
  while (!quit)
  {
    this_thread::sleep_for(chrono::milliseconds(25));
  }
}

void goWork()
{
  SDL_Event e;
  while (!quit)
  {

    listenner(e, quit);
    console.proc(mouse.x, mouse.y, mouse.leftKey);
    // if (!game->pause)
    // {
    //     game->prog();
    // }
    mouse.defaultKeys();
    this_thread::sleep_for(chrono::milliseconds(25));
  }
};

class Unit
{
public:
  Unit(int n);
  virtual void print() {};
  string str;
  string type;
  int number;

private:
};

class Peon : public Unit
{
public:
  Peon(int n) : Unit(n)
  {
  }
  void print() override
  {
    console.log("I em Pion !!!");
  };

private:
};

class Troll : public Unit
{
public:
  Troll(int n) : Unit(n)
  {
  }
  void print() override
  {
    console.log("I em Troll !!!");
  };

private:
};

int main()
{
  srand(time(0));

  // console.log("papa loh");
  Array<Unit *> *test = new Array<Unit *>(100);

  for (int i = 0; i < 10; i++)
  {
    // Unit *el = test->getElem(i);
    if (test->getElem(i) == nullptr)
    {
      if (i % 2 == 0)
      {
        Peon *peon = new Peon(1);
        peon->str = "i em pion";
        test->add(peon);
      }
      else
      {
        Troll *troll = new Troll(2);

        test->add(troll);
      }
    }
  };

  // console.log(to_string(test->length));

  // rapid<Unit*>* rap = new rapid<Unit*>;
  // rap->backForce(10);
  // rap->push(new Troll(2));
  // rap->forEach([](Unit *unit, int i){
  //  // unit->print();
  //  console.log(unit->str);
  // });

  test->forEach([](Unit *item, int i, Unit **arr)
                {
                   Unit *el = item;
                  //  delete el;
                  //  el = nullptr;
                  //  arr[i] = nullptr;
                     el->str = "i em changed";
                     console.log(el->str); });

  Troll *troll = new Troll(46);
   test->add(troll);
   console.log(to_string(test->findIndex([](Unit *item){
    if (item->number == 46) {
      return true;
    }
    return false;
   })));

 // console.log(to_string(test->length));

  //   for (int i = 0; i < test->getSize(); i++ ) {
  //      Unit *el = test->getElem(i);
  //      if (el != nullptr) {
  //         el->print();
  //      }
  //  };

  delete test;
  test = nullptr;
  // rapid<string> *strArr = new rapid<string>; // ok

  ctx.getFont();

  thread th_h(hard);
  thread th(goWork);
  //  SDL_Event e;

  while (!quit)
  {
    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");
    console.draw();
    ctx.End();
  }

  ctx.Close();

  th_h.join();
  th.join();

  return 0;
}

Unit::Unit(int n)
{
  this->number = n;
}

// void Unit::print()
// {
// console.log(this->str);
// }
