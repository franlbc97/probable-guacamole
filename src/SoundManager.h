#pragma once
#include <fmod.hpp>
#include <fmod_errors.h>
#include <string>
class SoundManager
{
public:
	static bool init();
	static bool tick();
	static bool release();
	static FMOD::System * getSystem();
	static FMOD::Geometry * getGeometry();
	static bool CheckFMODErrors(FMOD_RESULT r);
	// y equals z in 3D
	static void createZoneReverb(FMOD_REVERB_PROPERTIES prop, const int & x, const int & y, const float & maxDistance);

	static FMOD_REVERB_PROPERTIES getPresetReverbProperties(std::string name);
};

