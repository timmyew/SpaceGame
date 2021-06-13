#include <SDL.h>
#include <vector>
#include "BasicObject.h"
#include "Global_Const.h"
#include "Timer.h"
#include "Physic.h"

#pragma once
class WeaponManager{
public:
	WeaponManager();
	~WeaponManager();

	int GetCount();

	void AddWeapon(BasicObject* obj);
	void Update();
	void Draw();

private:
	std::vector<BasicObject*>* vec_Weapon;
	Timer* timer;

	const int shotIntervall = 200;
};

