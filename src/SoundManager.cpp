#include "SoundManager.h"
#include <iostream>
#include <string>
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
	CheckFMODErrors(reverb->set3DAttributes(&vec, maxDistance/2.f, maxDistance));
}

FMOD_REVERB_PROPERTIES SoundManager::getPresetReverbProperties(std::string name)
{
	if (name == "Off")
		return FMOD_PRESET_OFF;
	if (name == "Generic")
		return FMOD_PRESET_GENERIC;
	if (name == "Padded cell")
		return FMOD_PRESET_PADDEDCELL;
	if (name == "Room")
		return FMOD_PRESET_ROOM;
	if (name == "Bathroom")
		return FMOD_PRESET_BATHROOM;
	if (name == "Living Room")
		return FMOD_PRESET_LIVINGROOM;
	if (name == "Stone room")
		return FMOD_PRESET_STONEROOM;
	if (name == "Auditorium")
		return FMOD_PRESET_AUDITORIUM;
	if (name == "Concert hall")
		return FMOD_PRESET_CONCERTHALL;
	if (name == "Cave")
		return FMOD_PRESET_CAVE;
	if (name == "Arena")
		return FMOD_PRESET_ARENA;
	if (name == "Hangar")
		return FMOD_PRESET_HANGAR;
	if (name == "Carpeted hallway")
		return FMOD_PRESET_CARPETTEDHALLWAY;
	if (name == "Hallway")
		return FMOD_PRESET_HALLWAY;
	if (name == "Stone corridor")
		return FMOD_PRESET_STONECORRIDOR;
	if (name == "Alley")
		return FMOD_PRESET_ALLEY;
	if (name == "Forest")
		return FMOD_PRESET_FOREST;
	if (name == "City")
		return FMOD_PRESET_CITY;
	if (name == "Mountains")
		return FMOD_PRESET_MOUNTAINS;
	if (name == "Quarry")
		return FMOD_PRESET_QUARRY;
	if (name == "Plain")
		return FMOD_PRESET_PLAIN;
	if (name == "Parking lot")
		return FMOD_PRESET_PARKINGLOT;
	if (name == "Sewer pipe")
		return FMOD_PRESET_SEWERPIPE;
	if (name == "Underwater")
		return FMOD_PRESET_UNDERWATER;
	std::cout << "the preset " << name << " is not defined in FMOD, so fuck you" << std::endl;
	return FMOD_PRESET_GENERIC;
}


