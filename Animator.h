#include <SDL.h>
#include "Sprites.h"
#include "Timer.h"
#include <math.h>

#pragma once
class Animator{
public:
	bool iteration = false;

	Animator();
	~Animator();

	bool isAlive();

	void Draw(SDL_Renderer* renderer);

	void SetSprite(Sprites* sprite);
	void SetIntervall(int intervall);
	void SetSize(int x, int y, int width, int height, int angle);
	void SetAngle(int angle);
	void SetAlive(bool alive);

	SDL_Rect* GetRect();

private:
	Sprites* sprite = NULL;
	SDL_Rect* rect;
	Timer* timer;

	int intervall = 50;
	int pastTime = 0;
	int indexX = 0;
	int indexY = 0;

	bool alive = true;
};

