#include "Component.h"
#include "AppObject.h"
#include "errcheck.h"
#include <fmod.hpp>




bool DragMouseComponent::init(AppObject * obj)
{
	return true;
}

void DragMouseComponent::tick(AppObject * obj)
{
}

bool DragMouseComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return false;
}

