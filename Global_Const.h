#include <string.h>
#include "TextureManager.h"
#pragma once

//Player 
static const char* S_PLAYER = "./assets/spaceship.png";
static const int I_PLAYER_WIDTH = 90;
static const int I_PLAYER_HEIGHT = 40;
static const char* S_LASER = "./assets/laser.png";

//Background
static const char* S_BACKGROUND = "./assets/Background.png";

//Meteor
static const char* S_METEOR = "./assets/meteor.png";
static const char* S_EXPLOSION = "./assets/detonate_9x9.png";

//Window Size
static int WINDOW_WIDTH = 800;
static int WINDOW_HEIGHT = 600;

//Live
static const char* S_LIVE = "./assets/live.png";
extern Texture* liveTex;
static int const I_LIVEHEIGHT = 3;

//FPS
static int framePerSecond = 0;

//Core
static const char* FONT_PATH = "./assets/fonts/arial.ttf";