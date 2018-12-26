#include "PlayerControllerComponent.h"

PlayerControllerComponent::PlayerControllerComponent()
{
}

PlayerControllerComponent::~PlayerControllerComponent()
{
}

bool PlayerControllerComponent::init(AppObject * obj)
{
	return false;
}

void PlayerControllerComponent::render(SDL_Renderer * r, AppObject * obj)
{
}

void PlayerControllerComponent::tick(AppObject * obj)
{
}

bool PlayerControllerComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return false;
}

void PlayerControllerComponent::release(AppObject * obj)
{
}

const char * PlayerControllerComponent::getType()
{
	return "PlayerControllerComponent";
}
