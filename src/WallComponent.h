#pragma once
#include "Component.h"
#include <fmod.hpp>
class WallComponent:public Component
{
public:
	WallComponent(FMOD::Geometry * geometry);
	~WallComponent();
	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);
	

private:
	FMOD::Geometry* _geo;
	int polygonIndex;
	float directOclusion;
	float reverbOcclusion;

};


