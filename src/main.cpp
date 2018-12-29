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
#include "Reverb3DComponent.h"









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
		rectRender = new RectRenderComponent(SDL_Color{ 255,255,255,255 });
		buildMap("a");


		AppObject * appObj = new AppObject();
		appObjects.push_back(appObj);
		
		appObj->setX(500 - 15);
		appObj->setY(500 - 15);
		appObj->addComponent(rectRender);
		appObj->addComponent(new PlayerControllerComponent());
		ListenerComponent * lc = new ListenerComponent();
		appObj->addComponent(lc);
		
		/*
		AppObject *wall1 = new AppObject();
		wall1->setX(0);
		wall1->setY(360);
		wall1->setH(30);
		wall1->setW(1000);
		WallComponent * Wall = new WallComponent( 1.f, 1.0f);
		

		wall1->addComponent(Wall);
		wall1->addComponent(rectRender);
		appObjects.push_back(wall1);
		*/

		


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
				appobj->setCollidable(false);
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
	
	void buildMap(std::string file) {
		TMXReader::MapData mapilla("../Media/Maps/mapaNormal.tmx");
		for (size_t i = 0; i < mapilla.totalObjGroups(); i++)
		{
			TMXReader::Objectgroup* objGroup = mapilla.getObjectGroup(i);
			if (objGroup->getName() == "Walls") {
				for (size_t j = 0; j < objGroup->groupSize(); j++)
				{
					AppObject * wall = new AppObject();
					appObjects.push_back(wall);
					wall->setX(objGroup->at(j)->getX());
					wall->setY(objGroup->at(j)->getY());
					wall->setW(objGroup->at(j)->getW());
					wall->setH(objGroup->at(j)->getH());

					wall->addComponent(rectRender);
					wall->addComponent(new WallComponent(1.f, 1.f));

				}
			}
			else if (objGroup->getName() == "Zones") {
				for (size_t j = 0; j < objGroup->groupSize(); j++)
				{
					/*
					int x, y;
					x = objGroup->at(j)->getX();
					y = objGroup->at(j)->getY();
					AppObject * reverbObj = new AppObject();
					reverbObj->setCanBeSeleceted(false);
					reverbObj->setCollidable(false);
					reverbObj->setX(x);
					reverbObj->setY(y);
					reverbObj->setW(objGroup->at(j)->getW());
					reverbObj->setH(objGroup->at(j)->getH());
					reverbObj->addComponent(new Reverb3DComponent(SoundManager::getPresetReverbProperties(objGroup->at(j)->getType())));
					appObjects.push_back(reverbObj);
					*/
				}
			}
		}

	}

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