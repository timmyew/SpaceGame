#include "Sprites.h"

Sprites::Sprites(){
	this->rect = new SDL_Rect();
}

Sprites::~Sprites(){
	delete this->rect;
}

void Sprites::Draw(SDL_Renderer* renderer, SDL_Rect* destRect){
	SDL_RenderCopyEx(renderer, tex, rect, destRect, angle, NULL, SDL_FLIP_NONE);
}

void Sprites::Select(int xpos, int ypos){
	this->rect->x = xpos * spriteWidth;
	this->rect->y = ypos * spriteHeight;
	this->rect->w = spriteWidth;
	this->rect->h = spriteHeight;
}

void Sprites::SetAngle(int angle){
	this->angle = angle;
}

void Sprites::SetSpriteSheet(SDL_Texture* spritesheet, int x, int y){
	SDL_QueryTexture(spritesheet, NULL, NULL, &width, &height);

	spriteWidth = x;
	spriteHeight =  y;

	spriteCountX = width / x;
	spriteCountY = height /y;

	tex = spritesheet;
}


int Sprites::GetXCount(){
	return spriteCountX;
}

int Sprites::GetYCount(){
	return spriteCountY;
}