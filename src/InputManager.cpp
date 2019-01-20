#include "InputManager.h"
#include <SDL_mouse.h>

bool InputManager::init()
{
	return false;
}

SDL_Point InputManager::getMousePosition(const int & offsetX, const int & offsetY)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	
	return {x+offsetX,y+offsetY};
}

SDL_Point InputManager::getMousePosition(const SDL_Point & offset)
{
	return getMousePosition(offset.x,offset.y);
}
