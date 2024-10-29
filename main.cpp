// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "body/game/gameField/offsetControl.cpp"

// class Unit
// {
// public:
//   Unit(string* s) {
//     this->str = *s;
//   };
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
 string path = "levels/test_1.txt";
// mapWrite(&path, testMap);
 GameField *gameField = new GameField(&path, 1);

// vector<ProtoObj *> *vec = new vector<ProtoObj *>;

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

     gameField->offsetControl();

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

  int ver = 0;

  while (!quit)
  {
    

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

    ctx.CreateDrawZone(gameField->x, gameField->y, gameField->screenWidth, gameField->screenHeight);
    ctx.FillRect(gameField->x, gameField->y, gameField->screenHeight, gameField->screenHeight, "white");

    



    ctx.CreateDrawZone(0, 0, 700, 68);
    ctx.FillRect(0, 0, 700, 68, "green");

    ctx.CreateDrawZone(700, 0, 324, ctx.SCREEN_HEIGHT);
    ctx.FillRect(700, 0, 324, ctx.SCREEN_HEIGHT, "black");



       gameField->miniMapDraw();

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);

 

    console.draw();
    ctx.End();
  }


  delete gameField;
  gameField = nullptr;

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
