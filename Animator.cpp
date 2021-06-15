#include "Animator.h"

Animator::Animator(){
	timer = new Timer();
	rect = new SDL_Rect();
}

Animator::~Animator(){
	sprite = NULL;
	delete timer;
	delete rect;
}

bool Animator::isAlive(){
	return alive;
}

void Animator::Draw(SDL_Renderer* renderer){
	if (sprite && alive){

		if (timer->is_started()) {
			timer->pause();

			pastTime += timer->get_ticks();

			if (pastTime >= intervall){
				if (indexX >= sprite->GetXCount()){
					indexX = indexX - sprite->GetXCount();
					indexY ++;

					if (indexY > sprite->GetYCount() && indexX < sprite->GetXCount() + 1){
						indexX = 0;
						indexY = 0;

						if (!iteration){
							alive = false;
						}
					}
				}
				else{
					indexX += ceil(pastTime / intervall);
				}
			}

			//Draw if it alive
			if (alive){
				sprite->Select(indexX, indexY);
				sprite->Draw(renderer, rect);
			}

		}
		timer->start();
	}
}

void Animator::SetSprite(Sprites* sprite){
	this->sprite = sprite;
	this->sprite->Select(0, 0);

	indexX = 0;
	indexY = 0;
}

void Animator::SetIntervall(int intervall){
	this->intervall = intervall;
}

void Animator::SetSize(int x, int y, int width, int height, int angle){
	if (sprite){
		rect->x = x;
		rect->y = y;
		rect->w = width;
		rect->h = height;
		sprite->SetAngle(angle);
	}
}

void Animator::SetAngle(int angle){
	sprite->SetAngle(angle);
}

void Animator::SetAlive(bool alive){
	this->alive = alive;
}

SDL_Rect* Animator::GetRect(){
	if (sprite){
		return rect;
	}
	else{
		return NULL;
	}
}
