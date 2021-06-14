#include "Player.h"
#include "Global_Const.h"

Player::Player(SDL_Renderer* renderer) : BasicObject(renderer){
	SDL_Rect* rec = GetRect();

	rec->x = 0;
	rec->y = 0;
	rec->w = I_PLAYER_WIDTH;
	rec->h = I_PLAYER_HEIGHT;

	laserTex = NULL;
	manager = new WeaponManager();
}

Player::~Player(){
	delete manager;
}

void Player::SetLaserTexture(Texture* laserTex){
	this->laserTex = laserTex;
}

BasicObject* Player::GetWeaponAtIndex(int index){
	BasicObject* obj = manager->GetWeaponAt(index);

	const char* a = typeid(obj).name();
	const char* b = typeid(LaserBeam).name();

	if (typeid(obj).name() == typeid(LaserBeam).name()) {
		damage = LASER_DAMAGE;
	}

	return manager->GetWeaponAt(index);
}

int Player::GetWeaponCount(){
	return manager->GetCount();
}

int Player::GetDamage(){
	return damage;
}

void Player::Update(){
	BasicObject::Update();

	//DOWN
	if (isDown){
		//Too high
		if  (GetRect()->y + GetRect()->h + GetVeloCity()->GetY() > WINDOW_HEIGHT + 1){
			GetRect()->y = WINDOW_HEIGHT - GetRect()->h;
			GetVeloCity()->SetY(-GetVeloCity()->GetY());
		}
		else if (GetVeloCity()->GetY() != SPEED){
			GetVeloCity()->SetY(SPEED);
		}
	}

	//UP
	if (isUp){
		//Too low
		if (GetRect()->y - GetVeloCity()->GetY() <= 0){
			GetRect()->y = 0;
			GetVeloCity()->SetY(-GetVeloCity()->GetY());
		}
		else if (GetVeloCity()->GetY() != -SPEED){
			GetVeloCity()->SetY(-SPEED);
		}
	}

	//Stop hor
	if (!isUp && !isDown)
	{
		GetVeloCity()->SetY(-GetVeloCity()->GetY());
	}

	//Left
	if (isLeft){		
		//Too Left
		if (GetRect()->x - GetVeloCity()->GetX() <= 0){
			GetRect()->x = 0;
			GetVeloCity()->SetX(-GetVeloCity()->GetX());
		}
		else if (GetVeloCity()->GetX() != -SPEED){
			GetVeloCity()->SetX(-SPEED);
		}
	}

	//Right
	if (isRight){
		//Too Right			
		if  (GetRect()->x + GetRect()->w + GetVeloCity()->GetX() > WINDOW_WIDTH + 1){
			GetRect()->x = WINDOW_WIDTH - GetRect()->w;
			GetVeloCity()->SetX(-GetVeloCity()->GetX());
		}
		else if (GetVeloCity()->GetX() != SPEED){
			GetVeloCity()->SetX(SPEED);
		}
	}

	//Stop ver
	if (!isLeft && !isRight){
		GetVeloCity()->SetX(-GetVeloCity()->GetX());
	}

	if (isShoot){
		LaserBeam* laser = new LaserBeam(GetRenderer());
		laser->SetTexture(laserTex);
		laser->GetRect()->x = GetRect()->x + GetRect()->w - 15;
		laser->GetRect()->y = GetRect()->y + (GetRect()->h / 2) - 1;

		manager->AddWeapon(laser);

		std::cout << "Anzahl Laser geschosse: " << manager->GetCount() << std::endl;
	}

	manager->Update();
}

void Player::Draw(){
	BasicObject::Draw();
	manager->Draw();
}

void Player::KeyHandler(SDL_Event* event){
	if (event->key.keysym.scancode == SDL_SCANCODE_DOWN){
		isDown = event->key.type == SDL_KEYDOWN;
	}

	if (event->key.keysym.scancode == SDL_SCANCODE_UP){
		isUp = event->key.type == SDL_KEYDOWN;
	}

	if (event->key.keysym.scancode == SDL_SCANCODE_LEFT){
		isLeft = event->key.type == SDL_KEYDOWN;
	}

	if (event->key.keysym.scancode == SDL_SCANCODE_RIGHT){
		isRight = event->key.type == SDL_KEYDOWN;
	}

	if (event->key.keysym.scancode == SDL_SCANCODE_SPACE){
		isShoot = event->key.type == SDL_KEYDOWN;
	}

}
