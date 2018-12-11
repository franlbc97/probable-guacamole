#pragma once
#include "Component.h"
#include <fmod.hpp>

class SoundComponent : public Component
{
public:
	SoundComponent(FMOD::System *sys, const char * file) {
		file_ = file;
		systemSound_ = sys;
	}

	virtual ~SoundComponent() { sound_->release(); }

	// Heredado vía Component
	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj);
	virtual void tick(AppObject * obj);

	virtual bool handleInput(SDL_Event & e, AppObject * obj);

	void changePosition3D(const int & x, const int & y, const int & z);

	void setVolume(const float & nVol);

	inline float getVolume() {
		float vol;
		channelSound_->getVolume(&vol);
		return vol;
	};

	void togglePause();

	virtual void release(AppObject * obj);

private:
	const char * file_;
	FMOD::System* systemSound_;
	FMOD::Channel* channelSound_;
	FMOD::Sound* sound_;
};