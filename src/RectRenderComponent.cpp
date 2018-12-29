#include "RectRenderComponent.h"
#include "AppObject.h"
#include "GraphicManager.h"

RectRenderComponent::RectRenderComponent(SDL_Color color) :_color(color)
{
	
	
}

void RectRenderComponent::render( AppObject * obj)
{
	if (GraphicManager::isInCamera(obj->getRect())) {
		GraphicManager::drawRect(obj->getRect(), _color);
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
