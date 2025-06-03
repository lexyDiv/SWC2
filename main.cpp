// g++ main.cpp -I./include -o program `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -I./GLM/
// ./program
#include "methods/deleter/process.cpp"

bool quit = false;
int tik = 0;

ProtoGame *game = new Game();

// string path = "levels/test_1.txt";
// string path2 = "levels/testBig_1.txt";
// string path3 = "levels/testBig_500.txt";

// // mapWrite(&path, testMap);
// ProtoGameField *gameField = new GameField(&path, 1);

// vector<ProtoObj *> *vec = new vector<ProtoObj *>;

void hard()
{

  game->create();

  while (!quit)
  {

    if (game->isGFComplite)
    {
      game->getPotentialWayControl();
    }

    this_thread::sleep_for(chrono::milliseconds(1));
  }
}

void goWork()
{

  SDL_Event e;
  while (!quit)
  {

    if (game->isGFComplite)
    {
    // game->preDraw();

      game->objMenu->getCandidateCells();
      game->fractionsControl();

      deleter.process();
    }

    listenner(e, quit);
    console.proc(mouse.x, mouse.y, mouse.leftKey);

    this_thread::sleep_for(chrono::milliseconds(15));
  }
};

///////////////////////////////  kata
//////////////////////////////////

int main()
{

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

 //console.log(nationsHub->orcs.getItem(0).color); // ok


  srand(time(0));

  //  console.log("papa loh");

  ctx.getFont();

  thread th_h(hard);
  thread th(goWork);
  //  SDL_Event e;

  int stop = 0;

  while (!quit)
  {

    //   if (tik % 100 == 0) {
    //   delete game;
    //   game = nullptr;
    //   game = new Game();
    //   game->create();
    // }
    // if (game) {

    //  console.log("loading");



    ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
    ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");

    if (game->isGFComplite)
    {
      game->preDraw();
      game->draw();
      // potential way draw
      // if (game->objMenu->unit && game->objMenu->unit->isPotentialWayComplite)
      // {
      //   game->objMenu->unit->potentialWay.forEach([](ProtoObj *cell)
      //                                             {
      //     float drawDeltaX = game->gf->drawDeltaX;
      //     float drawDeltaY = game->gf->drawDeltaY;
      //     ctx.FillRect(cell->x + drawDeltaX, cell->y + drawDeltaY,
      //     cell->gabX, cell->gabY, "red"); });
      // }

      // if (hzCell) {
      //   ProtoObj* cell = hzCell;
      //     float drawDeltaX = game->gf->drawDeltaX;
      //     float drawDeltaY = game->gf->drawDeltaY;
      //     ctx.FillRect(cell->x + drawDeltaX, cell->y + drawDeltaY,
      //     cell->gabX, cell->gabY, "violet");
      // }

      // openArr draw
      // game->gf->openArr.forEach([](ProtoObj *cell){
      //     float drawDeltaX = game->gf->drawDeltaX;
      //     float drawDeltaY = game->gf->drawDeltaY;
      //     ctx.FillRect(cell->x + drawDeltaX, cell->y + drawDeltaY,
      //     cell->gabX, cell->gabY, "blue");
      // });


    }

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

    this_thread::sleep_for(chrono::milliseconds(15)); // 15 ok
  }

  delete game;
  game = nullptr;

  ctx.Close();

  th_h.join();
  th.join();

  return 0;
}
