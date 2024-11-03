// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "body/game/game/preDraw.cpp"

bool quit = false;
int tik = 0;

ProtoGame *game = new Game();

// string path = "levels/test_1.txt";
// string path2 = "levels/testBig_1.txt";
string path3 = "levels/testBig_500.txt";

// // mapWrite(&path, testMap);
// ProtoGameField *gameField = new GameField(&path, 1);

// vector<ProtoObj *> *vec = new vector<ProtoObj *>;

void hard()
{


// vector<string> vec;
// for (int i = 0; i < 500; i ++) {
//   string str = "";
//   for (int i = 0; i < 500; i ++) {
//      str += "0";
//   }
//   vec.push_back(str);
// }
// mapWrite(&path3, vec);



        game->create();
    

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

  int stop = 0;

  //gameField->create();

  while (!quit)
  {


  //   if (tik % 100 == 0) {
  //   delete game;
  //   game = nullptr;
  //   game = new Game();
  //   game->create();
  // }
//if (game) {

  //  console.log("loading");


   

    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");



      game->preDraw();
      game->draw();

//  if ( game && game->gf && game->gf->init) {
//    ProtoObj *cell = game->gf->field.getItem(0).getItem(0);
//     cell->maxAroundCells
//     .forEach([cell](ProtoObj *c, int i){
//       int dis = cell->maxAroundCellsDis.getItem(i);
//     float drawDeltaX = game->gf->drawDeltaX;
//     float drawDeltaY = game->gf->drawDeltaY;

//        if (dis <= c->gabX * 11) {
//         c->mapColor.R = 255;
//        }  
//             if ( dis <= c->gabX * 9.5) {
//          c->mapColor.G = 0;
//         }
//        ctx.DrawText(c->x + drawDeltaX, c->y + drawDeltaY + 5, 10,  to_string(dis), 255);
//     });
//  }
    

    console.draw();
    ctx.End();
  //  mouse.defaultKeys();
  }

   delete game;
   game = nullptr;
   
  ctx.Close();

  th_h.join();
  th.join();

  return 0;
}
