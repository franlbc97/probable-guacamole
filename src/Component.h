#pragma once
#include <SDL.h>
#include "AppObject.h"
#include <fmod.hpp>
#include "errcheck.h"
#define SCALE_FACTOR 0.01f

class Component
{
public:
	virtual bool init(AppObject * obj) = 0;
	virtual void render(SDL_Renderer * r, AppObject * obj) =0;
	virtual void tick(AppObject * obj) = 0;
	virtual bool handleInput(SDL_Event & e) = 0;
	
};

class SoundComponent : public Component
{
public:
	SoundComponent(FMOD::System *sys, const char * file) {
		file_ = file;
		systemSound_ = sys;
	}

	// Heredado vía Component
	virtual bool init(AppObject * obj) {
		ERRCHECK(systemSound_->createSound(file_, FMOD_3D, 0, &sound_));
		ERRCHECK(systemSound_->playSound(sound_, 0, true, &channelSound_));
		changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());

		return true;
	}
	virtual void render(SDL_Renderer * r, AppObject * obj) 
	{
	}

	virtual void tick(AppObject * obj) 
	{
		changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
		
	}

	virtual bool handleInput(SDL_Event & e) 
	{
		return false;
	}

	void changePosition3D(const int & x, const int & y, const int & z) {
		FMOD_VECTOR pos;
		FMOD_VECTOR vel;
		channelSound_->get3DAttributes(&pos, &vel);

		pos.x = (x)* SCALE_FACTOR;
		pos.y = (y)* SCALE_FACTOR;
		pos.z = (z)* SCALE_FACTOR;

		ERRCHECK(channelSound_->set3DAttributes(&pos, &vel));
	};

	void togglePause() {
		bool b;
		channelSound_->isPlaying(&b);
		channelSound_->setPaused(!b);
	}
private:
	const char * file_;
	FMOD::System* systemSound_;
	FMOD::Channel* channelSound_;
	FMOD::Sound* sound_;
};
