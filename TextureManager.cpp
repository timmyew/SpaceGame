#include "TextureManager.h"

Texture::Texture(SDL_Texture* texture){
	tex = texture;
}

Texture::~Texture(){
	SDL_DestroyTexture(tex);
	tex = NULL;
}

SDL_Texture* Texture::getTexture(){
	return tex;
}

TextureManager::TextureManager(){
	textureVec = new std::vector<Texture*>();
	spritesVec = new std::vector<Sprites*>(); 

	loadedSurface = NULL;
}

TextureManager::~TextureManager(){
	for (int i = 0; i < textureVec->size(); i++){
		delete textureVec->at(i);
	}

	textureVec->clear();
	delete textureVec;

	for (int i = 0; i < spritesVec->size(); i++){
		delete spritesVec->at(i);
	}

	spritesVec->clear();
	delete spritesVec;
}

Texture* TextureManager::LoadImage(const char* path, SDL_Renderer* renderer){
	loadedSurface = NULL;
	loadedSurface = IMG_Load(path);

	//If Image loaded
	if (loadedSurface != NULL) {
		//Create the Texture

		//Add The Texture to the map
		textureVec->push_back(new Texture(SDL_CreateTextureFromSurface(renderer, loadedSurface)));

		std::cout << "Texture: " << path << " is loaded!..." << std::endl;
	}
	else
		std::cout << "Unable to create texture from %s! SDL Error: %s\n" << path << SDL_GetError() << std::endl;

	return textureVec->at(textureVec->size() - 1);
}

Sprites* TextureManager::LoadSprite(const char* path, SDL_Renderer* renderer, int x, int y){
	Texture* tex = LoadImage(path, renderer);
	Sprites* sprites = new Sprites();

	sprites->SetSpriteSheet(tex->getTexture(), x, y);

	spritesVec->push_back(sprites);
	sprites = NULL;
	return spritesVec->at(spritesVec->size()-1);
}


