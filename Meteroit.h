#include "BasicObject.h"

#pragma once
class Meteroit : public BasicObject{
public:

	Meteroit(SDL_Renderer* renderer);
	~Meteroit();

	void Update() override;
	void Draw() override;
	bool Alive();

	void DecLive(int damage);

private:
	const int DEFAULT_SPEED = -3;
	bool isAlive = true;
	bool isFirstUpdate = true;
	int live = 0;

	SDL_Rect liveRec;
	
};

