// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "body/game/game/preDraw.cpp"

bool quit = false;
int tik = 0;

ProtoGame *game = new Game();

// string path = "levels/test_1.txt";
// string path2 = "levels/testBig_1.txt";

// // mapWrite(&path, testMap);
// ProtoGameField *gameField = new GameField(&path, 1);

// vector<ProtoObj *> *vec = new vector<ProtoObj *>;

void hard()
{


// vector<string> vec;
// for (int i = 0; i < 256; i ++) {
//   string str = "";
//   for (int i = 0; i < 256; i ++) {
//      str += "0";
//   }
//   vec.push_back(str);
// }
// mapWrite(&path2, vec);

  while (!quit)
  {

  //   if (gameField->init) {
  //     //     for (int i = 0; i < 100; i ++) {
  //     // if (quit) {
  //     //   break;
  //     // }
  //     gameField->field.forEach([](Array<ProtoObj *> arr){
  //       arr.forEach([](ProtoObj *cell){
  //         ProtoObj *cellCopy = cell;
  //         cell->mapColor.R = intRand(0, 255);
  //         cell->mapColor.G = intRand(0, 255);
  //         cell->mapColor.B = intRand(0, 255);
  //       });
  //     });
  // //  }
  //   }

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


    this_thread::sleep_for(chrono::milliseconds(20));
  }
};

int main()
{

  game->create();

  srand(time(0));

  //  console.log("papa loh");

  ctx.getFont();

  thread th_h(hard);
  thread th(goWork);
  //  SDL_Event e;

  int ver = 0;

  //gameField->create();

  while (!quit)
  {

    game->preDraw();

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

    game->draw();

    console.draw();
    ctx.End();

  }

   delete game;
   game = nullptr;
   
  ctx.Close();

  th_h.join();
  th.join();

  return 0;
}
