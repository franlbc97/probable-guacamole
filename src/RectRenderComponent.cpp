#include "RectRenderComponent.h"
#include "AppObject.h"
#include "GraphicManager.h"

RectRenderComponent::RectRenderComponent(SDL_Color color) :_color(color)
{
	
}

void RectRenderComponent::render(SDL_Renderer * r, AppObject * obj)
{
	if (GraphicManager::isInCamera(obj->getRect())) {
		SDL_SetRenderDrawColor(r, _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(r, &obj->getRect());

	}
}

bool RectRenderComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return true;
}

const char * RectRenderComponent::getType()
{
	return "RectRenderComponent";
}
