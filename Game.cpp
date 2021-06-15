#include "Game.h"

extern Texture* liveTex = NULL;

Game::Game(){
	isRunning = false;

	event = new SDL_Event();
	texManager = new TextureManager();	
}

Game::~Game(){
	delete texManager;
	delete sprite;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	delete event;

	std::cout << "Game is cleared!..." << std::endl;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

	int flag = 0;

	if (fullscreen)
		flag = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		std::cout << "SDL is Initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);

		if (window){
			std::cout << "Window is Initialised!..." << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer) {
				std::cout << "Renderer is Initialised!..." << std::endl;

				if (!(TTF_Init() < 0)) {
					std::cout << "SDL_TTF is Initialised!..." << std::endl;

					isRunning = true;
				}

				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			}
		}

		//Init Global
		liveTex = texManager->LoadImage(S_LIVE, renderer);

		//Init the Player
		spaceShip = new Player(renderer);
		spaceShip->SetTexture(texManager->LoadImage(S_PLAYER, renderer));
		spaceShip->SetLaserTexture(texManager->LoadImage(S_LASER, renderer));

		//Init Meteors
		meteorGen = new MeteorGenerator(renderer, texManager->LoadImage(S_METEOR, renderer));
		sprite = new Sprites();
		sprite->SetSpriteSheet(texManager->LoadImage(S_EXPLOSION, renderer)->getTexture(), 92, 90);

		meteorGen->SetExplosionSprite(sprite);

		backgroundTex = texManager->LoadImage(S_BACKGROUND, renderer);

		//Background 1
		backgroundRec = new SDL_Rect();
		backgroundRec->x = 0;
		backgroundRec->y = 0;
		backgroundRec->h = WINDOW_HEIGHT;
		backgroundRec->w = WINDOW_WIDTH;

		//Background 2
		backgroundRec2 = new SDL_Rect();
		backgroundRec2->x = WINDOW_WIDTH;
		backgroundRec2->y = 0;
		backgroundRec2->h = WINDOW_HEIGHT;
		backgroundRec2->w = WINDOW_WIDTH;

		//Init Utils
		fps = new Fps();
		fpsView = new BasicObject(renderer);
		fpsView->SetFontColor({128, 128, 128, 255});
		fpsView->SetFontPath(FONT_PATH);
		fpsView->SetFontSize(30);
	}
}

void Game::handleEvents(){
	SDL_PollEvent(event);
	switch (event->type){
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		spaceShip->KeyHandler(event);
		break;
	}
}

void Game::update(){
	UpdateBackground();

	fps->update();
	framePerSecond = fps->getFps();

	spaceShip->Update();
	meteorGen->Update();

	CheckMeteoritAndWeaponCollision();
}

void Game::render(){
	SDL_RenderClear(renderer);

	//Moveable Background
	Graphics::Draw(renderer, backgroundTex->getTexture(), backgroundRec);
	Graphics::Draw(renderer, backgroundTex->getTexture(), backgroundRec2);	

	spaceShip->Draw();
	meteorGen->Draw();

	fpsView->DrawFont(("FPS: " + std::to_string(framePerSecond)).c_str());

	SDL_RenderPresent(renderer);
}

bool Game::running(){
	return isRunning;
}

void Game::UpdateBackground(){
	backgroundRec->x = backgroundRec->x - 2;

	if (backgroundRec->x <= (-1 * WINDOW_WIDTH)) {
		backgroundRec->x = WINDOW_WIDTH;
	}

	backgroundRec2->x = backgroundRec2->x - 2;

	if (backgroundRec2->x <= (-1 * WINDOW_WIDTH)) {
		backgroundRec2->x = WINDOW_WIDTH;
	}
}

void Game::CheckMeteoritAndWeaponCollision(){
	for (int i = 0; i < spaceShip->GetWeaponCount(); i++){
		for (int j = 0; j < meteorGen->GetMeteroitCount(); j++){
			if (Physic::isCollided(spaceShip->GetWeaponAtIndex(i)->GetRect(), meteorGen->GetMeteroitAt(j)->GetRect())) {
				meteorGen->GetMeteroitAt(j)->DecLive(spaceShip->GetDamage(), spaceShip->GetWeaponAtIndex(i)->GetRect()->y);
				spaceShip->DeleteWeaponByIndex(i);
				break;
			}
		}
	}
}
