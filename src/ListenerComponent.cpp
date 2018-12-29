#include "ListenerComponent.h"
#include <iostream>
#include "AppObject.h"
#include "SoundManager.h"
bool ListenerComponent::init(AppObject * obj)
{
	systemSound_ = SoundManager::getSystem();
	systemSound_->set3DNumListeners(1);
	tick(obj);
	FMOD_VECTOR fow, up;
	systemSound_->get3DListenerAttributes(0, NULL, NULL, &fow, &up);
	//printf("%d %d %d \n", fow.x, fow.y, fow.z);
	//printf("%d %d %d \n", up.x, up.y, up.z);
	fow.z = 1;
	up.y = 1;


	systemSound_->set3DListenerAttributes(0, NULL, NULL, &fow, &up);
	return true;
}

void ListenerComponent::tick(AppObject * obj)
{
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
	//changeOrientation(obj->getFacing().x,0.f, -obj->getFacing().y);
}

void ListenerComponent::release(AppObject * obj)
{
}

void ListenerComponent::changePosition3D(const int & x, const int & y, const int & z)
{
	FMOD_VECTOR pos;
	systemSound_->get3DListenerAttributes(0, &pos, NULL, NULL, NULL);

	pos.x = float(x);
	pos.y = float(y);
	pos.z = float(z);

	systemSound_->set3DListenerAttributes(0, &pos, NULL, NULL, NULL);
}

void ListenerComponent::changeOrientation(const float & x, const float & y, const float & z)
{
	FMOD_VECTOR fow;
	systemSound_->get3DListenerAttributes(0, NULL, NULL,&fow, NULL);

	fow.x = x;
	fow.y = y;
	fow.z = z;

	systemSound_->set3DListenerAttributes(0, NULL, NULL, &fow, NULL);
}

