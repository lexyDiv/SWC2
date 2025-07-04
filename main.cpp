// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
// ./program

// g++ main.cpp -I./include -fmax-include-depth=3000 -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/

#include "methods/deleter/process.cpp"

std::mutex lock1;
std::mutex lock2;

bool quit = false;
int tik = 0;

ProtoGame *game = new Game();

// string path = "levels/test_1.txt";
// string path2 = "levels/testBig_1.txt";
// string path3 = "levels/testBig_500.txt";

// // mapWrite(&path, testMap);
// ProtoGameField *gameField = new GameField(&path, 1);

// vector<ProtoObj *> *vec = new vector<ProtoObj *>;

bool hardReady = true;
  // int hold2 = 0;
void hard()
{



  while (!quit)
  {
    hardReady = false;
    //  console.log(to_string(needReturn));
    if (game->isGFComplite &&
        !needReturn)
    {
   game->getPotentialWayControl2();
    }

    hardReady = true;

    this_thread::sleep_for(chrono::nanoseconds(1));
  }
}

bool goWorkReady = true;

void goWork()
{
  game->create();
  SDL_Event e;
  while (!quit)
  {

    // console.log(to_string(needReturn));
    if (!needReturn)
    {
      lock1.lock();
      goWorkReady = false;
      lock1.unlock();
      // game->preDraw();

      // game->objMenu->getCandidateCells();
      // game->fractionsControl();
      // game->gf->trupsControl();
      // game->gf->activeShahtsControl();

      // deleter.process();

      game->getPotentialWayControl();
      lock1.lock();
      goWorkReady = true;
      lock1.unlock();
    }

    // listenner(e, quit);
    // console.proc(mouse.x, mouse.y, mouse.leftKey);

    this_thread::sleep_for(chrono::nanoseconds(1)); // 15
  }
};

///////////////////////////////  kata
//////////////////////////////////

// class Hz {
//   public:
//   Hz() {};
//   ~Hz() {};
// };

// class HH : public Hz {
//    public:
//    HH() : Hz() {};
//    ~HH() {};
//    ProtoObj *j = nullptr;
// };

int main()
{

  // Hz hz;
  // HH hh;
  // console.log("Hz: " + to_string(sizeof(hz)));
  // console.log("HH: " + to_string(sizeof(hh)));

  // string literas = "!#$%&(),-;@+=0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.:/' ";
  // for (int i = 0; i < literas.size(); i++) {
  //  char c = literas[i];
  //  string cr = string{c};
  //  string cr_to_str = to_string(c);
  //  string res = cr + " = " + cr_to_str;
  //   console.log(res);
  // }

  ///////////////////////////////
  // json j;

  //  string path = "strings/test_1.txt";
  //   std::ifstream in(path); // окрываем файл для чтения
  //   string line;
  //   string resStr = "";
  //   if (in.is_open())
  //   {

  //       while (std::getline(in, line))
  //       {
  //         resStr += line;
  //          // std::cout << line << std::endl;
  //         // arr.push(line);
  //       }
  //   }
  //   in.close();     // закрываем файл
  //   json hz = json::parse(resStr);
  //    console.log(to_string(hz["field"].size()));
  /////////////////////

  // for (it = data.begin(); it != data.end(); ++it){
  //     std::cout << it->name;
  // }

  // for (int i = 0; i < testMap.size(); i++) {
  //   string line = testMap[i];
  //   j["plan"].push_back(line);
  // } // ok!

  // for (json::iterator it = j.begin(); it != j.end(); ++it) {
  //  // std::cout << *it << '\n';
  //  string value = *it;
  //  string res = it.key() + " : " + value;
  //  console.log(res); // key
  // }

  //////////////////////////////////// kata res
  ////////////////////

  // console.log(nationsHub->orcs.getItem(0).color); // ok

  srand(time(0));

  //  console.log("papa loh");

  ctx.getFont();

  // thread th(goWork);// ok
  // th.join();
  // thread th_h(hard);
  // th_h.join();
  SDL_Event e;

  int stop = 0;

  // ProtoGame po;
  // console.log("ProtoObj: " + to_string(sizeof(po)));
  // Game cl;
  // console.log("ProtoObj: " + to_string(sizeof(cl)));

  thread th(goWork); // ok
  thread th_h(hard);
  // th.detach();

  while (true)
  {

    if (!quit)
    {
      lock2.lock();
      needReturn = true;
      lock2.unlock();

      this_thread::sleep_for(chrono::nanoseconds(1));
      // th.join();

      if (goWorkReady && hardReady)
      {
        ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
        ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

        if (game->isGFComplite)
        {

          game->objMenu->getCandidateCells();
          game->fractionsControl();
          game->gf->trupsControl();
          game->gf->activeShahtsControl();

          deleter.process();

          game->preDraw();
          game->draw();
        }

        listenner(e, quit);
        console.proc(mouse.x, mouse.y, mouse.leftKey);

        console.draw();
        ctx.End();
      }

      lock2.lock();
      needReturn = false;
      lock2.unlock();
    }
    else
    {
      lock2.lock();
      needReturn = true;
      lock2.unlock();
      th.join();
      th_h.join();
      this_thread::sleep_for(chrono::milliseconds(1));
      if (goWorkReady)
      {
        delete game;
        game = nullptr;

        ctx.Close();
        break;
      }
    }

    this_thread::sleep_for(chrono::milliseconds(14)); // 15 ok
  }

  // th_h.join();
  // th.join();

  return 0;
}
