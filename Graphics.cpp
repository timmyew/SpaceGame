#include "Graphics.h"

void Graphics::Draw(SDL_Renderer* renderer, SDL_Texture* tex, SDL_Rect* rec, int angle){
	SDL_RenderCopyEx(renderer, tex, NULL, rec, angle, NULL, SDL_FLIP_NONE);
}

void Graphics::Draw(SDL_Renderer* renderer, SDL_Texture* tex, SDL_Rect* rec){
	Draw(renderer, tex, rec, 0);
}

void Graphics::DrawRect(SDL_Renderer* renderer, SDL_Rect* rect, SDL_Color color){
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, rect);
}

void Graphics::DrawText(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color color, int x, int y){
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* tex = NULL;
	SDL_Rect rec;

	if (!textSurface){
		std::cout << "Failed to render text!..." << std::endl;
	}
	else{
		rec.x = x;
		rec.y = y;
		rec.w = textSurface->w;
		rec.h = textSurface->h;

		tex = SDL_CreateTextureFromSurface(renderer, textSurface);
		Draw(renderer, tex, &rec);

		SDL_DestroyTexture(tex);
		SDL_FreeSurface(textSurface);
	}
}
