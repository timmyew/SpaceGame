#include "Meteroit.h"
#include "Global_Const.h"

Meteroit::Meteroit(SDL_Renderer* renderer, Sprites* sprite) : BasicObject(renderer){
	GetVeloCity()->SetX(DEFAULT_SPEED);

	liveRec.h = I_LIVEHEIGHT;
	vecExplosions = new std::vector<Explosion*>();
	spriteExplosion = sprite;
}

Meteroit::~Meteroit(){
	for (int i = 0; i < vecExplosions->size(); i++){
		delete vecExplosions->at(i);
	}

	vecExplosions->clear();
	delete vecExplosions;
}

void Meteroit::Update(){
	BasicObject::Update();

	isAlive = ((GetRect()->x + GetRect()->w) > 0);

	liveRec.x = GetRect()->x;
	liveRec.y = GetRect()->y - liveRec.h;

	//Set the live || Bad programming and english :D
	if (isFirstUpdate){
		live = GetRect()->w;
	}

	liveRec.w = live;

	UpdateExplosions();

	isFirstUpdate = false;
}

void Meteroit::Draw(){
	BasicObject::Draw();
	DrawExplosions();
	Graphics::Draw(GetRenderer(), liveTex->getTexture(), &liveRec);
}

bool Meteroit::Alive(){
	return isAlive;
}

void Meteroit::DecLive(int damage, int ypos){
	live -= damage;
	isAlive = live >= 0;

    vecExplosions->push_back(new Explosion(GetRenderer()));
	vecExplosions->at(vecExplosions->size() - 1)->GetAnimator()->SetSprite(spriteExplosion);
	vecExplosions->at(vecExplosions->size() - 1)->GetAnimator()->GetRect()->w = DEFAULT_EXPLOSION;
	vecExplosions->at(vecExplosions->size() - 1)->GetAnimator()->GetRect()->h = DEFAULT_EXPLOSION;
	vecExplosions->at(vecExplosions->size() - 1)->GetAnimator()->GetRect()->x = GetRect()->x - vecExplosions->at(vecExplosions->size() - 1)->GetAnimator()->GetRect()->w / 2;
	vecExplosions->at(vecExplosions->size() - 1)->GetAnimator()->GetRect()->y = ypos - vecExplosions->at(vecExplosions->size() - 1)->GetAnimator()->GetRect()->w / 2;
}

void Meteroit::DrawExplosions(){
	for (int i = 0; i < vecExplosions->size(); i++){
		vecExplosions->at(i)->GetAnimator()->Draw(GetRenderer());
	}
}

void Meteroit::UpdateExplosions(){
	for (int i = 0; i < vecExplosions->size(); i++){
		vecExplosions->at(i)->GetAnimator()->GetRect()->x = GetRect()->x - vecExplosions->at(i)->GetAnimator()->GetRect()->w / 2;
	}
}
