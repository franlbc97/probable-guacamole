#pragma once
#include "Component.h"
class PlayerControllerComponent
	:public Component
{
public:
	PlayerControllerComponent();
	~PlayerControllerComponent();
	virtual bool init(AppObject * obj);
	virtual void render(AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);
	virtual const char * getType();

private:
	int _movementAmount;


};
