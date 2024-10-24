// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "body/game/gameField/GameField.cpp"

// class Unit
// {
// public:
//   Unit() {};
//   Unit(int n);
//   virtual void print() {};
//   string str;
//   string type;
//   int number;
//   bool isProc = false;
//   bool isActive = false;

// private:
// };

// class Peon : public Unit
// {
// public:
//   Peon(int n) : Unit(n)
//   {
//   }
//   void print() override
//   {
//     console.log("I em Pion !!!");
//   };

// private:
// };

// class Troll : public Unit
// {
// public:
//   Troll(int n) : Unit(n)
//   {
//   }
//   void print() override
//   {
//     console.log("I em Troll !!!");
//   };

// private:
// };

/////////////////////////////////

bool quit = false;
int tik = 0;

//vector<ProtoObj *> *vec = new vector<ProtoObj *>;

void hard()
{

  // for (int i = 0; i < 10000000; i++)
  // {
  //   ProtoObj *pr = new ProtoObj;
  //   float rand = (float)intRand(0, 100);
  //   pr->x = rand;
  //   vec->push_back(pr);
  // }


  // for (int i = 0; i < vec->size(); i++)
  // {
  //   ProtoObj *p = vec->at(i);
  //   delete p;
  //   p = nullptr;
  // }
  // delete vec;
  // vec = nullptr;

  // vec->erase(remove_if(vec->begin(), vec->end(), [](ProtoObj *el)
  //                      { return el == nullptr; }),
  //            vec->end()); // delete all by if
  // vec->erase(vec->begin() + 0); // удаление элемента по индексу
  // vec->erase(find(vec->begin(),vec->end(), pr)); // удаление эл по элементу
  // sort(vec->begin(), vec->end(), [](ProtoObj* a, ProtoObj *b){
  //   return a->x < b->x;
  // }); // sort 


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

  console.log("papa loh");

  ctx.getFont();

  thread th_h(hard);
  thread th(goWork);
  //  SDL_Event e;

  while (!quit)
  {

    //  console.log(to_string(sizeof(*vec)));

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

    ctx.CreateDrawZone(0, 68, 700, 700);
    ctx.FillRect(0, 68, 700, 700, "yellow");

    ctx.CreateDrawZone(0, 0, 700, 68);
    ctx.FillRect(0, 0, 700, 68, "green");

    ctx.CreateDrawZone(700, 0, 324, ctx.SCREEN_HEIGHT);
    ctx.FillRect(700, 0, 324, ctx.SCREEN_HEIGHT, "black");

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);

    console.draw();
    ctx.End();
  }

  // for (int i = 0; i < vec->size(); i++)
  // {
  //   ProtoObj *p = vec->at(i);
  //   delete p;
  //   p = nullptr;
  // }
  // delete vec;
  // vec = nullptr;

  ctx.Close();

  th_h.join();
  th.join();

  return 0;
}

// Unit::Unit(int n)
// {
//   this->number = n;
// }

// void Unit::print()
// {
// console.log(this->str);
// }
