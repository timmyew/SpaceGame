#include "Meteroit.h"
#include "Global_Const.h"

Meteroit::Meteroit(SDL_Renderer* renderer) : BasicObject(renderer){
	GetVeloCity()->SetX(DEFAULT_SPEED);

	liveRec.h = I_LIVEHEIGHT;
}

Meteroit::~Meteroit(){
}

void Meteroit::Update(){
	BasicObject::Update();

	isAlive = ((GetRect()->x + GetRect()->w) > 0);

	liveRec.w = GetRect()->w;
	liveRec.x = GetRect()->x;
	liveRec.y = GetRect()->y - liveRec.h;

	//Set the live || Bad programming and english :D
	if (isFirstUpdate){
		live = GetRect()->w;
	}

	liveRec.w = ((live * 100) / GetRect()->w);

	isFirstUpdate = false;
}

void Meteroit::Draw(){
	BasicObject::Draw();

	Graphics::Draw(GetRenderer(), liveTex->getTexture(), &liveRec);
}

bool Meteroit::Alive(){
	return isAlive;
}

void Meteroit::DecLive(int damage){
	live -= damage;
	isAlive = live >= 0;
}
