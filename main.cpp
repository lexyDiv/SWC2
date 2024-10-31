// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "body/game/gameField/miniMapMouseControl.cpp"

bool quit = false;
int tik = 0;
string path = "levels/test_1.txt";
// mapWrite(&path, testMap);
ProtoGameField *gameField = new GameField(&path, 1);

// vector<ProtoObj *> *vec = new vector<ProtoObj *>;

void hard()
{

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

  srand(time(0));

  //  console.log("papa loh");

  ctx.getFont();

  thread th_h(hard);
  thread th(goWork);
  //  SDL_Event e;

  int ver = 0;

  gameField->create();

  while (!quit)
  {

    if (gameField->init)
    {
      gameField->miniMapMouseControl();
      gameField->offsetControl();
    }

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

    if (gameField->init)
    {
      ctx.CreateDrawZone(gameField->x, gameField->y, gameField->screenWidth, gameField->screenHeight);

      if (gameField->drawCell != nullptr)
      {

        gameField->drawCell->drawCells.forEach([](ProtoObj *cell)
                                               { cell->draw(); });
      }

      //  ctx.FillRect(gameField->centerX, gameField->centerY + gameField->y, 3, 3, "black");

      ctx.CreateDrawZone(0, 0, gameField->screenWidth, ctx.SCREEN_HEIGHT - gameField->screenHeight);
      ctx.FillRect(0, 0, gameField->screenWidth, ctx.SCREEN_HEIGHT - gameField->screenHeight, "blue");

      ctx.CreateDrawZone(gameField->screenWidth, 0, 324, ctx.SCREEN_HEIGHT);
      ctx.FillRect(gameField->screenWidth, 0, 324, ctx.SCREEN_HEIGHT, "black");

      gameField->miniMapDraw();
    }

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);

    console.draw();
    ctx.End();
  //  mouse.defaultKeys();
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
