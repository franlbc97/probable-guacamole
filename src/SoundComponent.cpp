#include "SoundComponent.h"
#include "SoundManager.h"
#include "AppObject.h"
#include "GraphicManager.h"

bool SoundComponent::init(AppObject * obj)
{

	systemSound_ = SoundManager::getSystem();

	(systemSound_->createSound(file_, FMOD_3D | FMOD_LOOP_NORMAL, 0, &sound_));
	(systemSound_->playSound(sound_, 0, false, &channelSound_));
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
	return true;

}

void SoundComponent::render( AppObject * obj)
{
	float audability;
	channelSound_->getAudibility(&audability);
	int color = 255 * audability;
	GraphicManager::drawRect(obj->getRect(), { 0,(Uint8)color,0});

}

void SoundComponent::tick(AppObject * obj)
{
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
}

const char * SoundComponent::getType()
{
	return "SoundComponent";
}

bool SoundComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	switch (e.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (e.button.button == SDL_BUTTON_RIGHT)
			togglePause();
		break;
	case SDL_MOUSEWHEEL:
		if (e.wheel.y > 0) {
			setVolume(getVolume() + 0.1f);
			return true;
		}
		if (e.wheel.y < 0) {
			setVolume(getVolume() - 0.1f);
			return true;
		}
		break;
	default:
		break;
	}
	return true;
}

void SoundComponent::changePosition3D(const int & x, const int & y, const int & z)
{
	FMOD_VECTOR pos;
	FMOD_VECTOR vel;
	channelSound_->get3DAttributes(&pos, NULL);

	pos.x = (x) ;
	pos.y = (y);
	pos.z = (z);

	(channelSound_->set3DAttributes(&pos, NULL));
}
void SoundComponent::setVolume(const float & nVol)
{
	if (nVol > 1.0f || nVol < 0.0f)
		return;
	float vol;
	channelSound_->getVolume(&vol);
	vol = nVol;
	channelSound_->setVolume(nVol);
}
float SoundComponent::getVolume()
{
	float vol;
	channelSound_->getVolume(&vol);
	return vol;
}
void SoundComponent::togglePause()
{

	(channelSound_->setPaused(false));
}

void SoundComponent::release(AppObject * obj)
{
}