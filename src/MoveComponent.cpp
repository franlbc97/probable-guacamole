#include "MoveComponent.h"


MoveComponent::MoveComponent(float max)
{
}


MoveComponent::~MoveComponent()
{
}


bool MoveComponent::init(AppObject * obj)
{
	return false;
}


void MoveComponent::render( AppObject * obj)
{
}


void MoveComponent::tick(AppObject * obj)
{
}


bool MoveComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return false;
}


void MoveComponent::release(AppObject * obj)
{
}


const char * MoveComponent::getType()
{
	return nullptr;
}
