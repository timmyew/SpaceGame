#include <SDL.h>
#include <vector>
#include "Graphics.h"

#pragma once
class Sprites{
public:

	Sprites();
	~Sprites();

	void Draw(SDL_Renderer* renderer, SDL_Rect* destRect);
	void Select(int xpos, int ypos);

	void SetAngle(int angle);
	void SetSpriteSheet(SDL_Texture* spritesheet, int x, int y);
	int GetXCount();
	int GetYCount();

private:
	int height = 0;
	int width = 0;

	int spriteCountX = 0;
	int spriteCountY = 0;

	int spriteWidth = 0;
	int spriteHeight = 0;

	int angle = 0;

	SDL_Texture* tex = NULL;
	SDL_Rect* rect;
};

