#include "RectRenderComponent.h"
#include "AppObject.h"

void RectRenderComponent::render(SDL_Renderer * r, AppObject * obj)
{
	SDL_SetRenderDrawColor(r, _color.r, _color.g, _color.b, _color.a);
	SDL_RenderFillRect(r, &obj->getRect());
}

bool RectRenderComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return true;
}
