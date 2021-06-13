#include "TextureManager.h"

Texture::Texture(SDL_Texture* texture){
	tex = texture;
}

Texture::~Texture(){
	tex = nullptr;
}

SDL_Texture* Texture::getTexture(){
	return tex;
}

TextureManager::TextureManager(){
	textureMap = new std::map<const char*, Texture>();
	loadedSurface = NULL;
}

TextureManager::~TextureManager(){

}

Texture* TextureManager::LoadImage(const char* path, SDL_Renderer* renderer){
	loadedSurface = NULL;
	loadedSurface = IMG_Load(path);

	//If Image loaded
	if (loadedSurface != NULL) {
		//Add The Texture to the map
		textureMap->emplace(path, Texture(SDL_CreateTextureFromSurface(renderer, loadedSurface)));

		std::cout << "Texture: " << path << " is loaded!..." << std::endl;
	}
	else
		std::cout << "Unable to create texture from %s! SDL Error: %s\n" << path << SDL_GetError() << std::endl;

	return &textureMap->at(path);
}


