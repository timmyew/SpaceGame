#include "BasicObject.h"
#include "Explosion.h"
#include <vector>
#include "Sprites.h"

#pragma once
class Meteroit : public BasicObject{
public:

	Meteroit(SDL_Renderer* renderer, Sprites* sprite);
	~Meteroit();

	void Update() override;
	void Draw() override;
	bool Alive();

	void DecLive(int damage, int ypos);

private:
	const int DEFAULT_SPEED = -3;
	bool isAlive = true;
	bool isFirstUpdate = true;
	int live = 0;

	const int DEFAULT_EXPLOSION = 40;

	SDL_Rect liveRec;
	std::vector<Explosion*>* vecExplosions;
	Sprites* spriteExplosion;

	void DrawExplosions();
	void UpdateExplosions();
};

