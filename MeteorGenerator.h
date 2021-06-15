#include <SDL.h>
#include <vector>
#include < cstdlib >
#include "Meteroit.h"
#include "Timer.h"
#include "TextureManager.h"
#include <iostream>
#include "Sprites.h"

#pragma once
class MeteorGenerator{
public:
	MeteorGenerator(SDL_Renderer* renderer, Texture* tex);
	~MeteorGenerator();

	void SetExplosionSprite(Sprites* sprite);
	void SetSpawnRate(int meteorPerSecond);
	Meteroit* GetMeteroitAt(int index);
	int GetMeteroitCount();

	void Update();
	void Draw();

private:
	//Meteor
	int spawnRate = 1;
	int minSize = 30;
	int maxSize = 120;
	int pastTime = 0;
	const int ROTATION_SPEED = 1;

	std::vector<Meteroit*>* vec_Meteors;
	Meteroit* tmpMeteor;
	Timer* timer;
	SDL_Renderer* renderer;
	Texture* tex;
	Sprites* spriteExplosion;


	void CreateMeteors();
};

