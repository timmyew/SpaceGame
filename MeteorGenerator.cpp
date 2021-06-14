#include "MeteorGenerator.h"
#include "Global_Const.h"

MeteorGenerator::MeteorGenerator(SDL_Renderer* renderer, Texture* tex){
	this->renderer = renderer;
	this->tex = tex;

	vec_Meteors = new std::vector<Meteroit*>();
	timer = new Timer();
}

MeteorGenerator::~MeteorGenerator(){
	for (size_t i = 0; i < vec_Meteors->size(); i++){
		delete vec_Meteors->at(i);
	}

	delete vec_Meteors;
	delete timer;
}

void MeteorGenerator::SetSpawnRate(int meteorPerSecond){
	spawnRate = meteorPerSecond;
}

Meteroit* MeteorGenerator::GetMeteroitAt(int index){
	return vec_Meteors->at(index);
}

int MeteorGenerator::GetMeteroitCount(){
	return vec_Meteors->size();
}

void MeteorGenerator::Update(){
	CreateMeteors();

	for (int i = 0; i < vec_Meteors->size(); i++) {
		//Delete the old Meteors
		if (!(vec_Meteors->at(i)->Alive())) {
			vec_Meteors->erase(vec_Meteors->begin() + i);
		}
		else{
			vec_Meteors->at(i)->Update();
		}
	}
}

void MeteorGenerator::Draw(){
	for (int i = 0; i < vec_Meteors->size(); i++) {
		vec_Meteors->at(i)->Draw();
	}
}

void MeteorGenerator::CreateMeteors(){	
	if (timer->is_started()) {
		timer->pause();

		pastTime += timer->get_ticks();

		if (pastTime >= 1000) {
			for (int i = 0; i < spawnRate; i++) {
				tmpMeteor = new Meteroit(renderer);
				tmpMeteor->SetTexture(tex);
				tmpMeteor->GetRect()->h = rand() % maxSize + minSize;
				tmpMeteor->GetRect()->w = tmpMeteor->GetRect()->h;
				tmpMeteor->GetRect()->x = WINDOW_WIDTH;
				tmpMeteor->GetRect()->y = rand() % (WINDOW_HEIGHT - tmpMeteor->GetRect()->w);

				int randValue = rand() % 3;

				//Set the Roation Value
				if (randValue == 1) {
					tmpMeteor->GetVeloCity()->SetRotate(ROTATION_SPEED);
				}
				else if (randValue == 2) {
					tmpMeteor->GetVeloCity()->SetRotate(-ROTATION_SPEED);
				}

				srand(time(NULL) + tmpMeteor->GetRect()->h);

				vec_Meteors->push_back(tmpMeteor);
				tmpMeteor = NULL;
			}
			pastTime = 0;
			std::cout << "Meteors created: " << spawnRate << ". Total Meteors: " << vec_Meteors->size() << std::endl;
		}
	}

	timer->start();
}
