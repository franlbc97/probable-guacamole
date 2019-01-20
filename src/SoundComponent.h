#pragma once
#include "Component.h"
#include <fmod.hpp>

class SoundComponent : public Component
{
public:
	/// <summary>
	/// The constructor of the Component
	/// </summary>
	/// <param name="file">Teh file</param>
	SoundComponent(const char * file) {
		file_ = file;
	}

	virtual ~SoundComponent() { sound_->release(); }

	
	virtual bool init(AppObject * obj);
	virtual void render(AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);
	virtual const char * getType();
	void togglePause();


	void changePosition3D(const int & x, const int & y, const int & z);

	void setVolume(const float & nVol);

	inline float getVolume() {
		float vol;
		channelSound_->getVolume(&vol);
		return vol;
	};



private:
	const char * file_;
	FMOD::System* systemSound_;
	FMOD::Channel* channelSound_;
	FMOD::Sound* sound_;
};