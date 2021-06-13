#include <iostream>
#include <SDL.h>
#include "Game.h"
#include "Global_Const.h"

int main(int argc, char* args[]) {
    
    int* i = new int[10];

    Game* game = new Game();
    game->init("Test_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    while (game->running()){   
        game->handleEvents();
        game->update();
        game->render();

        //60 FPS
        SDL_Delay(16);
    }

    game->~Game();
    return 0;
}