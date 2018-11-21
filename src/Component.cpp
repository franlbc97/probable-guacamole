#include "Component.h"
#include "AppObject.h"
#include "errcheck.h"
bool SoundComponent::init(AppObject * obj)
{

	ERRCHECK(systemSound_->createSound(file_, FMOD_3D, 0, &sound_));
	ERRCHECK(systemSound_->playSound(sound_, 0, true, &channelSound_));
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());

	return true;

}

void SoundComponent::tick(AppObject * obj)
{
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
}

bool SoundComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return true;
}

void SoundComponent::changePosition3D(const int & x, const int & y, const int & z)
{
	FMOD_VECTOR pos;
	FMOD_VECTOR vel;
	channelSound_->get3DAttributes(&pos, &vel);

	pos.x = (x)* SCALE_FACTOR;
	pos.y = (y)* SCALE_FACTOR;
	pos.z = (z)* SCALE_FACTOR;

	ERRCHECK(channelSound_->set3DAttributes(&pos, &vel));
}
void SoundComponent::togglePause()
{
	bool b;
	channelSound_->isPlaying(&b);
	channelSound_->setPaused(!b);
}

void RectRenderComponent::render(SDL_Renderer * r, AppObject * obj)
{
	SDL_SetRenderDrawColor(r, _color.r, _color.g, _color.b, _color.a);
	SDL_RenderFillRect(r, &obj->getRect());
}

bool RectRenderComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return true;
}

bool DragMouseComponent::init(AppObject * obj)
{
	return true;
}

void DragMouseComponent::tick(AppObject * obj)
{
}

bool DragMouseComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return true;
}
