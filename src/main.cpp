#include <SDL.h>
#include <SDL_main.h>
#include <iostream>
#include <SDL_video.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <list>
#include "AppObject.h"
#include "Component.h"












class SDLApp
{

public:
	SDLApp():running_(1),window_(0),soundSystem_(0)	{}
	~SDLApp() {}
	void initDependencies() {
	
		SDL_Init(SDL_INIT_EVERYTHING);
		window_ = SDL_CreateWindow("Game Window", 200, 200, 500, 500,SDL_WINDOW_OPENGL);

		renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.
		SDL_RenderClear(renderer_);
		SDL_RenderPresent(renderer_);


		FMOD::System_Create(&soundSystem_);
		soundSystem_->init(128, FMOD_INIT_NORMAL, 0);
		soundSystem_->set3DNumListeners(1);

		FMOD_VECTOR pos;
		FMOD_VECTOR vel;
		FMOD_VECTOR foward;
		FMOD_VECTOR up;
		soundSystem_->get3DListenerAttributes(0, &pos, &vel, &foward, &up);
		pos.x = (250 + 15)*SCALE_FACTOR;
		pos.z = (250 + 15)*SCALE_FACTOR;


		soundSystem_->set3DListenerAttributes(0,&pos,&vel,&foward,&foward);
		float doppler, dis, rolloff;
		soundSystem_->get3DSettings(&doppler,&dis, &rolloff);
		///*
		//dis = 100.f;
		//doppler = 500.f;
		//rolloff = 500.f;
		//*/

		soundSystem_->set3DSettings(doppler,dis, rolloff);
			


	}

	void initScene() {
		appObjects.push_back(new AppObject());
		std::list<AppObject*>::iterator it = appObjects.begin();
		(*it)->setX(250 - 15);
		(*it)->setY(250 - 15);
		//(*it)->setCanBeSeleceted(false);



	}

	void closeApp(){
		std::list<AppObject*>::iterator it = appObjects.begin();

		for (it; it != appObjects.end(); it++) {
			delete *it;
			*it = nullptr;

		}
		SDL_Quit();
		soundSystem_->release();
	}
	bool isRunning() { return running_; }

	void handleInput() {
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) {
				running_ = false;
				break;
			}
			if (e.type == SDL_DROPFILE) {
				
			}
			std::list<AppObject*>::iterator it = appObjects.begin();
			bool prosiga = true;
			for (it; it != appObjects.end() && prosiga; it++) {
				if ((*it)->handleInput(e))
					prosiga = false;

			}
		}


	}

	void tick(){
		for (auto it : appObjects)
			it->tick();
		soundSystem_->update();
	}
	void render() {

		SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.

		SDL_RenderClear(renderer_);

		for (auto it : appObjects)
			it->render(renderer_);

		SDL_RenderPresent(renderer_);

	}

	
private:
	std::list<AppObject*> appObjects;
	SDL_Window * window_;
	SDL_Renderer * renderer_;
	bool running_;
	FMOD::System * soundSystem_;
	Component * rectRender;
	Component * dragRender;
	Component * rectRender;
	Component * rectRender;

};




int main(int ac, char** av) {
	
	SDLApp app;
	app.initDependencies();
	app.initScene();
	while (app.isRunning())
	{
		app.handleInput();
		app.tick();
		app.render();

	}
	app.closeApp();
	return 0;
}