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
#include "WallComponent.h"
#include "GraphicManager.h"
#include "SoundManager.h"
#include "MapData.h"
#include "PlayerControllerComponent.h"









class SDLApp
{

public:
	SDLApp():running_(1)	{}
	~SDLApp() {}
	bool initDependencies() {
	
		if (GraphicManager::init()) 
		{
			printf("Initialiazion of GraphicManager Failed\n");
			return true;
		}
		if (SoundManager::init()) {
			printf("Initialiazion of SoundManager Failed\n");
			return true;
		}
			

		return false;
	}

	void initScene() {
		//TMXReader::MapData mapilla("../Media/Maps/mapaNormal.tmx");

		SoundManager::createZoneReverb(FMOD_PRESET_CAVE, 0, 0, 1000.f);

		rectRender = new RectRenderComponent(SDL_Color{ 255,255,255,255 });
		AppObject * appObj = new AppObject();
		appObjects.push_back(appObj);
		
		appObj->setX(500 - 15);
		appObj->setY(500 - 15);
		appObj->addComponent(rectRender);
		appObj->addComponent(new PlayerControllerComponent());
		ListenerComponent * lc = new ListenerComponent();
		appObj->addComponent(lc);
		
		AppObject *wall1 = new AppObject();
		wall1->setX(0);
		wall1->setY(360);
		wall1->setH(30);
		wall1->setW(1000);
		WallComponent * Wall = new WallComponent( 1.f, 1.0f);
		

		wall1->addComponent(Wall);
		wall1->addComponent(rectRender);
		appObjects.push_back(wall1);

		
		


	}

	void closeApp(){
		std::list<AppObject*>::iterator it = appObjects.begin();

		for (it; it != appObjects.end(); it++) {
			delete *it;
			*it = nullptr;

		}
	
		GraphicManager::release();
		SoundManager::release();
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
				SoundComponent * comp = new SoundComponent( e.drop.file);
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
		SoundManager::tick();
		for (auto it : appObjects)
			it->tick();
	}
	void render() {

		GraphicManager::tick();
		GraphicManager::clear();
		for (auto it : appObjects)
			it->render();
		GraphicManager::present();


	}

	
private:
	std::list<AppObject*> appObjects;
	bool running_;
	Component * rectRender;
	Component * dragRender;
	Component * soundComponent;
	//Component * rectRender;

};




int main(int ac, char** av) {
	printf("Game Started\n");
	
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