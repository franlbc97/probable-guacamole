#pragma once
#include <SDL.h>
#include <fmod.hpp>

#define SCALE_FACTOR 0.01f
class AppObject;

class Component
{
public:
	virtual bool init(AppObject * obj) = 0;
	virtual void render(SDL_Renderer * r, AppObject * obj) =0;
	virtual void tick(AppObject * obj) = 0;
	virtual bool handleInput(SDL_Event & e, AppObject * obj) = 0;
	
};
class DragMouseComponent: public Component
{
public:
	DragMouseComponent() {};
	virtual ~DragMouseComponent() {};
	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj) {}
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);

private:

};

class RectRenderComponent:public Component
{
public:
	RectRenderComponent(SDL_Color color) :_color(color) {};
	virtual ~RectRenderComponent() {};
	virtual bool init(AppObject * obj) { return true; };
	virtual void render(SDL_Renderer * r, AppObject * obj);
	virtual void tick(AppObject * obj) {};
	virtual bool handleInput(SDL_Event & e, AppObject * obj);

private:
	SDL_Color _color;

};



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

	void changePosition3D(const int & x, const int & y, const int & z) ;

	void setVolume(const float & nVol);

	inline float getVolume() {
		float vol;
		channelSound_->getVolume(&vol);
		return vol;
	};

	void togglePause();
private:
	const char * file_;
	FMOD::System* systemSound_;
	FMOD::Channel* channelSound_;
	FMOD::Sound* sound_;
};

class ListenerComponent : public Component
{
public:
	ListenerComponent(FMOD::System *sys): systemSound_(sys){};
	~ListenerComponent() {};
	
	virtual bool init(AppObject * obj);
	virtual void render(SDL_Renderer * r, AppObject * obj) {}
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj) { return false; }


	void changePosition3D(const int & x, const int & y, const int & z);


private:
	FMOD::System* systemSound_;

};

