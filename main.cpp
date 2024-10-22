// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "Listenner.h"


class Unit
{
public:
  Unit(){};
  Unit(int n);
  virtual void print() {};
  string str;
  string type;
  int number;
  bool isProc = false;

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

  Array<Unit *> *test = new Array<Unit *>(100);

/////////////////////////////////

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



int main()
{
  srand(time(0));

  // console.log("papa loh");









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

  delete test;
  test = nullptr;

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
