#pragma once
#include "Component.h"
class WallComponent:public Component
{
public:
	WallComponent();
	~WallComponent();
	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);

private:

};


