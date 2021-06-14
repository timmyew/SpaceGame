#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include "Graphics.h"
#include "TextureManager.h"
#include "Player.h"
#include "Global_Const.h"
#include <SDL_ttf.h>
#include "Fps.h"
#include <string> 
#include "MeteorGenerator.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();

	bool running();

private:
	//Core
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* event;

	//Graphic managing
	TextureManager* texManager;
	Texture* backgroundTex;
	SDL_Rect* backgroundRec;
	SDL_Rect* backgroundRec2;

	//Objects
	Player* spaceShip;
	MeteorGenerator* meteorGen;

	//Utils
	BasicObject* fpsView;
	Fps* fps;

	void UpdateBackground();
	void CheckMeteoritAndWeaponCollision();
};
