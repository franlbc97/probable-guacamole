#include "ListenerComponent.h"
#include <iostream>
#include "AppObject.h"
bool ListenerComponent::init(AppObject * obj)
{
	systemSound_->set3DNumListeners(1);
	tick(obj);
	FMOD_VECTOR fow, up;
	systemSound_->get3DListenerAttributes(0, NULL, NULL, &fow, &up);
	printf("%d %d %d \n", fow.x, fow.y, fow.z);
	printf("%d %d %d \n", up.x, up.y, up.z);
	fow.z = 1;


	systemSound_->set3DListenerAttributes(0, NULL, NULL, &fow, &up);
	return true;
}

void ListenerComponent::tick(AppObject * obj)
{
	changePosition3D(obj->getXMiddle(), 0, obj->getYMiddle());
}

void ListenerComponent::release(AppObject * obj)
{
}

void ListenerComponent::changePosition3D(const int & x, const int & y, const int & z)
{
	FMOD_VECTOR pos, vel, fow, up;
	systemSound_->get3DListenerAttributes(0, &pos, &vel, &fow, &up);

	pos.x = float(x)* SCALE_FACTOR;
	pos.y = float(y)* SCALE_FACTOR;
	pos.z = float(z)* SCALE_FACTOR;

	systemSound_->set3DListenerAttributes(0, &pos, &vel, &fow, &up);
}

