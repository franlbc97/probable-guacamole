#include "SDLApp.h"
#include "SoundManager.h"
#include "GraphicManager.h"
#include "RectRenderComponent.h"
#include "AppObject.h"
#include "ListenerComponent.h"
#include "PlayerControllerComponent.h"
#include "SoundComponent.h"
#include "AppObject.h"
#include "MapData.h"
#include "Reverb3DComponent.h"
#include "WallComponent.h"



SDLApp::SDLApp() :running_(1) {

}


SDLApp::~SDLApp()
{
}


bool SDLApp::initDependencies()
{


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


void SDLApp::initScene()
{

	rectRender = new RectRenderComponent(SDL_Color{ 255,255,255,255 });
	buildMap("../bin/mapaNormal2.tmx");
	

	AppObject * appObj = new AppObject();
	appObjects.push_back(appObj);

	appObj->setX(500 - 15);
	appObj->setY(500 - 15);
	appObj->setW(10);
	appObj->setH(10);
	
	appObj->addComponent(rectRender);
	appObj->addComponent(new PlayerControllerComponent());
	ListenerComponent * lc = new ListenerComponent();
	appObj->addComponent(lc);






}


void SDLApp::closeApp()
{

	std::list<AppObject*>::iterator it = appObjects.begin();

	for (it; it != appObjects.end(); it++) {
		delete *it;
		*it = nullptr;

	}

	GraphicManager::release();
	SoundManager::release();
}


bool SDLApp::isRunning()
{
	return running_;
}


void SDLApp::setRunning(bool nValue)
{
	running_ = nValue;
}


void SDLApp::handleInput()
{

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
			SoundComponent * comp = new SoundComponent(e.drop.file);
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


void SDLApp::tick()
{
	SoundManager::tick();
	GraphicManager::tick();
	for (auto it : appObjects)
		it->tick();
}


void SDLApp::render()
{
	GraphicManager::clear();
	for (auto it : appObjects)
		it->render();
	GraphicManager::present();
}


void SDLApp::buildMap(std::string file)
{

	TMXReader::MapData mapilla(file);
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
				
			}
		}
		else if (objGroup->getName() == "Sounds") {
			for (size_t j = 0; j < objGroup->groupSize(); j++)
			{
				int x, y;
				x = objGroup->at(j)->getX();
				y = objGroup->at(j)->getY();
				AppObject * obj = new AppObject();
				obj->setCanBeSeleceted(false);
				obj->setCollidable(false);
				obj->setX(x);
				obj->setY(y);
				obj->setW(objGroup->at(j)->getW());
				obj->setH(objGroup->at(j)->getH());
				string soundFile;
				objGroup->at(j)->getValue("file", soundFile);
				if(soundFile != "")
					obj->addComponent(new SoundComponent(soundFile.c_str()));
				appObjects.push_back(obj);
			}
		}
	}

}
