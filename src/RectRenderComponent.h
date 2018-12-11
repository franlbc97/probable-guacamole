#pragma once
#include "Component.h"
class RectRenderComponent :public Component
{
public:
	RectRenderComponent(SDL_Color color) :_color(color) {};
	virtual ~RectRenderComponent() {};
	virtual bool init(AppObject * obj) { return true; };
	virtual void render(SDL_Renderer * r, AppObject * obj);
	virtual void tick(AppObject * obj) {};
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj) {};

private:
	SDL_Color _color;

};