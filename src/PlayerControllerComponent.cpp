#include "PlayerControllerComponent.h"
#include "AppObject.h"
#include "GraphicManager.h"
PlayerControllerComponent::PlayerControllerComponent()
{
}

PlayerControllerComponent::~PlayerControllerComponent()
{
}

bool PlayerControllerComponent::init(AppObject * obj)
{
	keys.emplace(std::make_pair(SDLK_w, false));
	keys.emplace(std::make_pair(SDLK_s, false));
	keys.emplace(std::make_pair(SDLK_d, false));
	keys.emplace(std::make_pair(SDLK_a, false));
	obj->setCanBeSeleceted(false);
	return false;
}

void PlayerControllerComponent::render( AppObject * obj)
{

	
}

void PlayerControllerComponent::tick(AppObject * obj)
{
	//go up
	if (keys.at(SDLK_w)) {
		obj->move(0, -5);
	}
	//go down
	else if (keys.at(SDLK_s)) {
		obj->move(0, 5);
	}
	//go left
	if (keys.at(SDLK_a)) {
		obj->move(-5, 0);

	}
	//go right
	else if (keys.at(SDLK_d)) {
		obj->move(5, 0);

	}

}

bool PlayerControllerComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		updateKeys(e, true);
		break;
	case SDL_KEYUP:
		updateKeys(e, false);
		break;
	default:
		break;
	}
	return false;
}

void PlayerControllerComponent::release(AppObject * obj)
{
}

const char * PlayerControllerComponent::getType()
{
	return "PlayerControllerComponent";
}

void PlayerControllerComponent::updateKeys(SDL_Event & e, bool pressed)
{
	try
	{
		keys.at(e.key.keysym.sym) = pressed;
	}
	catch (const std::exception&)
	{

	}
}
