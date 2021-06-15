#include "Explosion.h"

Explosion::Explosion(SDL_Renderer* renderer) : BasicObject(renderer){
}

bool Explosion::isFinished(){
	return BasicObject::GetAnimator()->isAlive();
}
