#pragma once
#include "Component.h"
#include <fmod.hpp>
class WallComponent:public Component
{
public:

	WallComponent(const float & directOclusion,const float & reverbOcclusion);
	~WallComponent();
	virtual bool init(AppObject * obj);
	virtual void render( AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);
	virtual const char * getType();

	

private:

	int polygonIndex;
	float _directOclusion;
	float _reverbOcclusion;
	int indexes[4];

};


