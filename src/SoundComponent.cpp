#include "SoundComponent.h"

#include "AppObject.h"

bool SoundComponent::init(AppObject * obj)
{

	(systemSound_->createSound(file_, FMOD_3D | FMOD_LOOP_NORMAL, 0, &sound_));
	(systemSound_->playSound(sound_, 0, false, &channelSound_));
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());

	return true;

}

void SoundComponent::render(SDL_Renderer * r, AppObject * obj)
{

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
	channelSound_->get3DAttributes(&pos, &vel);

	pos.x = (x)* SCALE_FACTOR;
	pos.y = (y)* SCALE_FACTOR;
	pos.z = (z)* SCALE_FACTOR;

	(channelSound_->set3DAttributes(&pos, &vel));
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
void SoundComponent::togglePause()
{

	(channelSound_->setPaused(false));
}

void SoundComponent::release(AppObject * obj)
{
}