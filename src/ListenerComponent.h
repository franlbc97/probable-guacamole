#pragma once
#include "Component.h"
#include <fmod.hpp>

class ListenerComponent : public Component
{
public:
	ListenerComponent(FMOD::System *sys) : systemSound_(sys) {};
	~ListenerComponent() {};

	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj) {}
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj) { return false; }
	virtual void release(AppObject * obj);


	void changePosition3D(const int & x, const int & y, const int & z);


private:
	FMOD::System* systemSound_;

};