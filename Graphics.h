#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#pragma once
class Graphics{
public:
	static void Draw(SDL_Renderer* renderer, SDL_Texture* tex, SDL_Rect* rec, int angle);
	static void Draw(SDL_Renderer* renderer, SDL_Texture* tex, SDL_Rect* rec);
	static void DrawRect(SDL_Renderer* renderer, SDL_Rect* rect, SDL_Color color);
	static void DrawText(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color color, int x, int y);
};

