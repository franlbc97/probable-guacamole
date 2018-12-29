#pragma once
#include "Component.h"
#include <fmod.hpp>
class Reverb3DComponent: public Component
{
public:
	Reverb3DComponent(FMOD_REVERB_PROPERTIES props);
	~Reverb3DComponent();
	virtual bool init(AppObject * obj);
	virtual void render(AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);
	virtual const char * getType();

private:
	float maxDistance_;
	FMOD_REVERB_PROPERTIES props_;
	FMOD::Reverb3D * reverb_;
};
