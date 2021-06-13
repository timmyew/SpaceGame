#include "BasicObject.h"

BasicObject::BasicObject(SDL_Renderer* renderer){
	this->renderer = renderer;

	tex = NULL;
	texFont = NULL;
	texSurface = NULL;
	color = NULL;
	rec = new SDL_Rect();
	size = 12;

	velo = new VeloCity();
}

BasicObject::~BasicObject(){
	SDL_DestroyTexture(texFont);
	delete velo;
}

void BasicObject::SetAngle(int angle){
	this->angle = angle;
}

void BasicObject::SetFontSize(int size){
	this->size = size;
}

void BasicObject::SetFontColor(SDL_Color color){
	this->color = new SDL_Color(color);
}

void BasicObject::SetFontPath(const char* path){
	fontPath = path;
}

void BasicObject::SetTexture(Texture* tex){
	this->tex = tex;
}

int BasicObject::GetAngle(){
	return angle;
}

SDL_Rect* BasicObject::GetRect(){
	return rec;
}

const char* BasicObject::GetFontPath(){
	return fontPath;
}

int BasicObject::GetFontSize(){
	return size;
}

SDL_Color* BasicObject::GetFontColor(){
	return color;
}

VeloCity* BasicObject::GetVeloCity(){
	return velo;
}

SDL_Renderer* BasicObject::GetRenderer(){
	return renderer;
}

void BasicObject::Draw(){
	Graphics::Draw(renderer, tex->getTexture(), rec, angle);
}

void BasicObject::DrawFont(const char* text){
	if (!font){
		font = TTF_OpenFont(fontPath, size);
	}

	if (font){
		Graphics::DrawText(renderer, font, text, *color, rec->x, rec->y);
	}
}

void BasicObject::Update(){
	//Update Movement
	rec->x += velo->GetX();
	rec->y += velo->GetY();
	angle += velo->GetRotate();
}

void BasicObject::KeyHandler(SDL_Event* event){
	this->key = event->key;
}
