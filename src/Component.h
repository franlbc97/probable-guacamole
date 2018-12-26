#pragma once
#include <SDL.h>

#define SCALE_FACTOR 1.0f
class AppObject;

class Component
{
public:
	virtual bool init(AppObject * obj) = 0;
	virtual void render(SDL_Renderer * r, AppObject * obj) =0;
	virtual void tick(AppObject * obj) = 0;
	virtual bool handleInput(SDL_Event & e, AppObject * obj) = 0;
	virtual void release(AppObject * obj) = 0;
	virtual const char * getType() = 0;
	
};
class DragMouseComponent: public Component
{
public:
	DragMouseComponent() {};
	virtual ~DragMouseComponent() {};
	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj) {}
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj) {};

private:

};









