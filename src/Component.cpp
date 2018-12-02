#include "Component.h"
#include "AppObject.h"
#include "errcheck.h"
bool SoundComponent::init(AppObject * obj)
{

	ERRCHECK(systemSound_->createSound(file_, FMOD_3D | FMOD_LOOP_NORMAL, 0, &sound_));
	ERRCHECK(systemSound_->playSound(sound_, 0, false, &channelSound_));
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());

	return true;

}

void SoundComponent::render(SDL_Renderer * r, AppObject * obj)
{
	float volume = getVolume();
	SDL_Rect rectAux;
	rectAux.x = obj->getX();
	rectAux.y = obj->getY();
	rectAux.w = obj->getW() * volume;
	rectAux.h = obj->getH()/3;
	SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
	SDL_RenderFillRect(r, &rectAux);


}

void SoundComponent::tick(AppObject * obj)
{
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
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

	ERRCHECK(channelSound_->set3DAttributes(&pos, &vel));
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
	
	ERRCHECK(channelSound_->setPaused(false));
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
	return false;
}

bool ListenerComponent::init(AppObject * obj)
{
	systemSound_->set3DNumListeners(1);
	tick(obj);
	return true;
}

void ListenerComponent::tick(AppObject * obj)
{
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
}

void ListenerComponent::changePosition3D(const int & x, const int & y, const int & z)
{
	FMOD_VECTOR pos, vel, fow,up;
	systemSound_->get3DListenerAttributes(0,&pos, &vel,&fow,&up);

	pos.x = float(x)* SCALE_FACTOR;
	pos.y = float(y)* SCALE_FACTOR;
	pos.z = float(z)* SCALE_FACTOR;

	systemSound_->set3DListenerAttributes(0, &pos, &vel, &fow, &up);
}
