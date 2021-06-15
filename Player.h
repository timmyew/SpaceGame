#include "BasicObject.h"
#include "LaserBeam.h"
#include "WeaponManager.h"
#include "Physic.h"
#include <typeinfo>

#pragma once
class Player : public BasicObject{
public:
	Player(SDL_Renderer* renderer);
	~Player();

	void SetLaserTexture(Texture* laserTex);
	BasicObject* GetWeaponAtIndex(int index);
	int GetWeaponCount();
	int GetDamage();

	void DeleteWeaponByIndex(int index);

	void Update() override;
	void Draw() override;
	void KeyHandler(SDL_Event* event);

private:
	WeaponManager* manager;
	Texture* laserTex;

	bool isDown = false;
	bool isUp = false;
	bool isRight = false;
	bool isLeft = false;
	bool isShoot = false;

	const int SPEED = 10;
	const int LASER_DAMAGE = 20;
	int damage = 0;
};

