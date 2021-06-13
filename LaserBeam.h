#include "BasicObject.h"
#include <SDL.h>
#include "Global_Const.h"

#pragma once
class LaserBeam : public BasicObject{
public:
	LaserBeam(SDL_Renderer* renderer);
	~LaserBeam();

	void Update() override;

private:
	const int LENGTH = 20;
	const int HEIGHT = 5;
	const int SPEED = 20;
};

