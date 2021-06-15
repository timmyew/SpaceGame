#include "Graphics.h"
#include "TextureManager.h"
#include <SDL_events.h>
#include <SDL_ttf.h>
#include "VeloCity.h"
#include "Animator.h"

#pragma once
class BasicObject{
public:
	BasicObject(SDL_Renderer* renderer);
	~BasicObject();

	//Setter
	void SetAngle(int angle);
	void SetFontSize(int size);
	void SetFontColor(SDL_Color color);
	void SetFontPath(const char* path);
	void SetTexture(Texture* tex);

	//Getter
	int GetAngle();
	SDL_Rect* GetRect();
	const char* GetFontPath();
	int GetFontSize();
	SDL_Color* GetFontColor();
	VeloCity* GetVeloCity();
	SDL_Renderer* GetRenderer();
	Animator* GetAnimator();

	virtual void Draw();
	void DrawFont(const char* text);
	virtual void Update();
	void KeyHandler(SDL_Event* event);
private:
	//Images
	Texture* tex;
	SDL_Rect* rec;
	SDL_Renderer* renderer;
	SDL_KeyboardEvent key;

	//Animator
	Animator* animator;

	//Velocity
	VeloCity* velo;

	//Font
	TTF_Font* font;
	SDL_Texture* texFont;
	SDL_Surface* texSurface;
	SDL_Color* color;
	const char* fontPath;
	int size;
	int angle = 0;
};

