#include "RectRenderComponent.h"
#include "AppObject.h"
#include "GraphicManager.h"

RectRenderComponent::RectRenderComponent(SDL_Color color) :_color(color)
{
	
	
}

bool RectRenderComponent::init(AppObject * obj)
{
	return false;
}

void RectRenderComponent::render( AppObject * obj)
{
	if (GraphicManager::isInCamera(obj->getRect())) {
		GraphicManager::drawRect(GraphicManager::getRectRelativeToCamera(obj->getRect()), _color);
		
	}
}

void RectRenderComponent::tick(AppObject * obj)
{
}

bool RectRenderComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return true;
}

void RectRenderComponent::release(AppObject * obj)
{
}

const char * RectRenderComponent::getType()
{
	return "RectRenderComponent";
}
