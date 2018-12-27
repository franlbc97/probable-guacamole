#include "SoundManager.h"
#include <iostream>
static FMOD::System *_system;
static FMOD::Geometry * _geo;
bool SoundManager::init()
{
	if (CheckFMODErrors(FMOD::System_Create(&_system)))
		return true;
	if (CheckFMODErrors(_system->init(128, FMOD_INIT_NORMAL, 0)))
		return true;
	if(CheckFMODErrors(_system->set3DNumListeners(1)))
		return true;
	if(CheckFMODErrors(_system->set3DSettings(1.0f, 100.f, 1.0f)))
		return true;
	if(CheckFMODErrors(_system->createGeometry(150, 150,&_geo)))
		return true;
	_geo->setActive(true);
	return false;
}

bool SoundManager::tick()
{
	_system->update();
	return false;
}

bool SoundManager::release()
{
	_system->release();
	return false;
}

FMOD::System * SoundManager::getSystem()
{
	return _system;
}

FMOD::Geometry * SoundManager::getGeometry()
{
	return _geo;
}

bool SoundManager::CheckFMODErrors(FMOD_RESULT r)
{

		if (r != FMOD_OK) {
			std::cout << FMOD_ErrorString(r) << std::endl;
			// printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
			return true;
			//exit(-1);
		}
	
		return false;
}

void SoundManager::createZoneReverb(FMOD_REVERB_PROPERTIES prop, const int & x, const int & y, const float & maxDistance)
{
	FMOD::Reverb3D* reverb;
	CheckFMODErrors(_system->createReverb3D(&reverb));
	CheckFMODErrors(reverb->setProperties(&prop));
	FMOD_VECTOR vec;
	vec.x = x;
	vec.y = 0;
	vec.z = y;
	CheckFMODErrors(reverb->set3DAttributes(&vec, 10.f, maxDistance));
}


