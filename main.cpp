// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
#include "body/game/NeitralOjs/create.cpp"

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

// ProtoObj *hz = new Cell;
// ProtoObj *&copy = hz;
// copy->x = 69;
// delete hz;
// hz = nullptr;
// if (copy) {
//   console.log(to_string(copy->x));
// }


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

///////////////////////////////  kata
//////////////////////////////////

int main()
{

//////////////////////////////////// kata res
////////////////////

  srand(time(0));

  //  console.log("papa loh");

  ctx.getFont();

  thread th_h(hard);
  thread th(goWork);
  //  SDL_Event e;

  int stop = 0;

  //gameField->create();

//  vector<vector<int>> vec;
//  vector<int> ve;
//  vec.push_back(ve);

//  vector<int> &veCopy = vec[0];
//  veCopy.push_back(11);
//  //vec[0].push_back(11);

// if (vec[0][0]) {
//    console.log(to_string(vec[0][0]));
// }

// ProtoObj* pa = new ProtoObj;

// Array<Array<ProtoObj *>> arr;
// Array<ProtoObj *> a;
// arr.push(a);
// Array<ProtoObj *> &hz = arr.getItem3(0);
// hz.push(pa);
// console.log(to_string(arr.getItem(0).length));

  while (!quit)
  {

if ( game && game->gf && game->gf->init) {
//console.log(to_string(game->gf->planes.getItem(0)->contactPlanes.getItem(0)->cellsToOther.length));
}
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

    //  ctx.DrawImage(groundBasic, 0, 0, 100, 100, 100, 100, 200, 200);

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
