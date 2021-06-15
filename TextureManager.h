#include <SDL_assert.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <array>
#include "Sprites.h"

#pragma once
class Texture {
public:
	Texture(SDL_Texture* texture);
	~Texture();

	SDL_Texture* getTexture();

private:
	SDL_Texture* tex;
};


class TextureManager{
public:
	TextureManager();
	~TextureManager();

	//Gibt ein Texturenobjekt zurück 
	Texture* LoadImage(const char* path, SDL_Renderer* renderer);
	Sprites* LoadSprite(const char* path, SDL_Renderer* renderer, int x, int y);
private:
	 SDL_Surface* loadedSurface;
	 std::vector<Texture*>* textureVec;
	 std::vector<Sprites*>* spritesVec;
};

