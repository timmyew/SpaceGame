#include "Physic.h"

bool Physic::isCollided(SDL_Rect* recA, SDL_Rect* recB){
	return ((recA->x < (recB->x + recB->w)) && ((recA->x + recA->w) > recB->x)
		&& (recA->y < (recB->y + recB->h)) && ((recA->y + recA->h) > recB->y));
}
