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

	/// <summary>
	/// The destructor of the Component
	/// </summary>
	virtual ~SoundComponent() { sound_->release(); }

	/// <summary>
	/// Initializes the sound
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns>True if something fails, false in every other case</returns>
	virtual bool init(AppObject * obj);
	/// <summary>
	/// Render when thee sund is hearable by the listener, and the volume of the sound
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void render(AppObject * obj);
	/// <summary>
	/// Updates the position of the sound and the orientation
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void tick(AppObject * obj);
	/// <summary>
	/// Handles the input of the component
	/// </summary>
	/// <param name="e">The event</param>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns></returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="obj"></param>
	virtual void release(AppObject * obj);
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	virtual const char * getType();
	/// <summary>
	/// Toggles the pause and the pause
	/// </summary>
	void togglePause();

	/// <summary>
	/// Changes the position of the sound
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	void changePosition3D(const int & x, const int & y, const int & z);

	/// <summary>
	/// Sets the volume of the sounds volume
	/// </summary>
	/// <param name="nVol">The new volume value</param>
	void setVolume(const float & nVol);

	/// <summary>
	/// For getting the value of the volume
	/// </summary>
	/// <returns>the value of the volume</returns>
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