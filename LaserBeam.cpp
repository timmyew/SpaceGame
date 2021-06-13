#include "LaserBeam.h"
#include "Physic.h"

LaserBeam::LaserBeam(SDL_Renderer* renderer) : BasicObject(renderer){
	GetVeloCity()->SetX(SPEED);

	GetRect()->h = HEIGHT;
	GetRect()->w = LENGTH;
}

LaserBeam::~LaserBeam(){
}

void LaserBeam::Update(){
	BasicObject::Update();
}
