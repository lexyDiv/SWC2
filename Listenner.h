#pragma once

#include "union/FS/FS.h"

bool nextMove = false;

void listenner(SDL_Event e, bool &quit)
{
    while (SDL_PollEvent(&e) != 0)
    {
        // User requests quit
        if (e.type == SDL_QUIT)
        {

            quit = true;
        }
        if (e.type == SDL_KEYDOWN)
        {
            // console.log(to_string(e.key.keysym.scancode)); // int 40
            if (e.key.keysym.scancode == 40)
            {
                nextMove = true;
                // console.log("eneter");
                //  game->speed++;
                //  game->pause = false;
                // game->tryDel = true;
                // game->needForPause = false;
            }
            if (e.key.keysym.scancode == 44)
            {
                // game->pause = false;
            }
        }
        if (e.type == SDL_MOUSEMOTION)
        {
            mouse.move(e.motion.x, e.motion.y);
            // console.log(to_string(e.motion.x));
            mouse.isMove = true;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            // console.log(to_string(e.button.x)); // 1, 2, 3
            // WayPoint* pnt = new WayPoint(e.button.x, e.button.y);
            // fs.write("levels/level2.txt", pnt, sizeof(WayPoint));
            // wayLine->push(pnt);
            // pnt = nullptr;
            // console.log("click");

            mouse.pressKey(e.button.button);
            mouse.keyDown(e.button.button);
            // console.log("click point");
        }
        if (e.type == SDL_MOUSEBUTTONUP)
        {
            // console.log(to_string(e.button.button)); // 1, 2, 3
            mouse.upKey(e.button.button);
            mouse.keyUp(e.button.button);
        }
        if (e.type == SDL_MOUSEWHEEL)
        {

            console.whellOrder(e.motion.yrel);
        }
    }
    mouse.listen = true;
}