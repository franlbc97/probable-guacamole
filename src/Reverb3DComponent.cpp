#include "Reverb3DComponent.h"
#include "AppObject.h"
#include "SoundManager.h"
#include "GraphicManager.h"

Reverb3DComponent::Reverb3DComponent( FMOD_REVERB_PROPERTIES props):
	props_(props),
	reverb_(0)
{
}

Reverb3DComponent::~Reverb3DComponent()
{
	
}

bool Reverb3DComponent::init(AppObject * obj)
{
	maxDistance_= (obj->getH()>obj->getW()) ? obj->getH() : obj->getW();
	maxDistance_ /= 2.f;
	reverb_ = SoundManager::createZoneReverb(props_, obj->getXMiddle(), obj->getYMiddle(), maxDistance_);
	return false;
}

void Reverb3DComponent::render(AppObject * obj)
{
	if (GraphicManager::isInCamera(obj->getRect())){
		GraphicManager::drawCircle(obj->getXMiddle(), obj->getYMiddle(), maxDistance_, {255,0,255,255});

	}
}

void Reverb3DComponent::tick(AppObject * obj)
{
	
}

bool Reverb3DComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	return false;
}

void Reverb3DComponent::release(AppObject * obj)
{
	reverb_->release();
}

const char * Reverb3DComponent::getType()
{
	return "Reverb3D";
}

void Reverb3DComponent::changeReverbPosition(const int & x, const int & y)
{

	FMOD_VECTOR pos;
	reverb_->get3DAttributes(&pos, NULL, NULL);
	pos.x = x;
	pos.z = y;
	reverb_->set3DAttributes(&pos, NULL, NULL);
}
