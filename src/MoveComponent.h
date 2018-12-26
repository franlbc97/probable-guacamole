#pragma once
#include "Component.h"

class MoveComponent :
	public Component
{
public:
	enum Direction
	{
		DIR_NORTH,
		DIR_NORTH_EAST,
		DIR_EAST,
		DIR_SOUTH_EAST,
		DIR_SOUTH,
		DIR_SOUTH_WEST,
		DIR_WEST,
		DIR_NORTH_WEST,
	};
	MoveComponent(float max);
	~MoveComponent();
	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);
	virtual const char * getType() ;

private:
	float maxVelocity;
	


};
