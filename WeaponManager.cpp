#include "WeaponManager.h"

WeaponManager::WeaponManager(){
	vec_Weapon = new std::vector<BasicObject*>();
	timer = new Timer();
	timer->start();
}

WeaponManager::~WeaponManager(){
	for (int i = 0; i < vec_Weapon->size(); i++){
		vec_Weapon->erase(vec_Weapon->begin() + i);
	}

	delete vec_Weapon;
	delete timer;
}

BasicObject* WeaponManager::GetWeaponAt(int index){
	return vec_Weapon->at(index);
}

int WeaponManager::GetCount(){
	return vec_Weapon->size();
}

void WeaponManager::AddWeapon(BasicObject* obj){

	if (timer->is_started() && (timer->get_ticks() >= shotIntervall)){
		timer->stop();

		vec_Weapon->push_back(obj);
	}
	else{
		if (!timer->is_started()){
			timer->start();
		}

		delete obj;
	}

}

void WeaponManager::Update(){
	SDL_Rect window{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

	for (int i = 0; i < vec_Weapon->size(); i++){
		vec_Weapon->at(i)->Update();

		if (!Physic::isCollided(vec_Weapon->at(i)->GetRect(), &window)) {
			vec_Weapon->erase(vec_Weapon->begin() + i);
		}
	}

}

void WeaponManager::Draw(){
	for (int i = 0; i < vec_Weapon->size(); i++){
		vec_Weapon->at(i)->Draw();
	}
}

void WeaponManager::DeleteWeaponByIndex(int index){
	vec_Weapon->erase(vec_Weapon->begin() + index);
}
