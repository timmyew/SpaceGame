#include "BasicObject.h"
#include "LaserBeam.h"
#include "WeaponManager.h"
#include "Physic.h"

class Player : public BasicObject{
public:
	Player(SDL_Renderer* renderer);
	~Player();

	void SetLaserTexture(Texture* laserTex);

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
	int fireRate = 2;
};

