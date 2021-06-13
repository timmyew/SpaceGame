#include <SDL_assert.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <array>

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
private:
	 SDL_Surface* loadedSurface;
	 std::map<const char*, Texture>* textureMap;
};

