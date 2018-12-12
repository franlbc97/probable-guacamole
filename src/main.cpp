#include <SDL.h>
#include <SDL_main.h>
#include <iostream>
#include <SDL_video.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <list>
#include "AppObject.h"
#include "RectRenderComponent.h"
#include "ListenerComponent.h"
#include "SoundComponent.h"




void cheka(FMOD_RESULT result) {
	if (result != FMOD_OK) {
		std::cout << FMOD_ErrorString(result) << std::endl;
		// printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
		system("PAUSE");
		exit(-1);
	}
}







class SDLApp
{

public:
	SDLApp():running_(1),window_(0),soundSystem_(0)	{}
	~SDLApp() {}
	void initDependencies() {
	
		SDL_Init(SDL_INIT_EVERYTHING);
		window_ = SDL_CreateWindow("Game Window", 200, 200, 1280, 720,SDL_WINDOW_OPENGL);

		renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		SDL_SetRenderDrawColor(renderer_, 0, 100, 100, 255);  // Dark grey.
		SDL_RenderClear(renderer_);
		SDL_RenderPresent(renderer_);


		FMOD::System_Create(&soundSystem_);
		cheka(soundSystem_->init(128, FMOD_INIT_NORMAL, 0));
		cheka(soundSystem_->set3DNumListeners(1));
		soundSystem_->set3DSettings(1.0f, 100.f, 1.0f);
		

			


	}

	void initScene() {
		rectRender = new RectRenderComponent(SDL_Color{ 255,255,255,255 });
		AppObject * appObj = new AppObject();
		appObjects.push_back(appObj);
		
		appObj->setX(250 - 15);
		appObj->setY(250 - 15);
		appObj->addComponent(rectRender);
		
		ListenerComponent * lc = new ListenerComponent(soundSystem_);
		appObj->addComponent(lc);

		FMOD::Geometry *geo;
		cheka(soundSystem_->createGeometry(150, 150, &geo));
		FMOD_VECTOR verts[4];
		verts[0].x = 0;
		verts[0].y = 100;
		verts[0].z = 500;

		verts[1].x = 0;
		verts[1].y = -100;
		verts[1].z = 500;

		verts[2].x = 1000;
		verts[2].y = -100;
		verts[2].z = 500;

		verts[3].x = 1000;
		verts[3].y= 100;
		verts[3].z= 500;
		int index;
		cheka(geo->addPolygon(1.0f,0.0f, true, 4, verts, &index));
		cheka(geo->setActive(true));


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
				AppObject * appobj = new AppObject();
				int x, y;
				SDL_GetMouseState(&x, &y);
				appobj->setX(x);
				appobj->setY(y);
				appobj->addComponent(rectRender);
				SoundComponent * comp = new SoundComponent(soundSystem_, e.drop.file);
				appObjects.push_back(appobj);
				appobj->addComponent(comp);
				continue;
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
		soundSystem_->update();
		for (auto it : appObjects)
			it->tick();
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
	Component * soundComponent;
	//Component * rectRender;

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