#pragma once
#include <fmod.hpp>
#include <fmod_errors.h>
#include <string>
class SoundManager
{
public:
	/// <summary>
	/// For initialiazing everything that involves the sound
	/// </summary>
	/// <returns>true if something fails, every other case false</returns>
	static bool init();
	/// <summary>
	/// Updates the sound system
	/// </summary>
	/// <returns>If something fails, true, every other case false</returns>
	static bool tick();
	/// <summary>
	/// Release everything that involves the sound
	/// </summary>
	/// <returns>If something fail, true, every other case, false</returns>
	static bool release();

	/// <summary>
	/// For getting the FMOD::System of the manager
	/// </summary>
	/// <returns>the FMOD::System of the manager</returns>
	static FMOD::System * getSystem();
	/// <summary>
	/// for checking errors that involvolves FMOD
	/// </summary>
	/// <param name="r">The result of an operation that involves FMOD</param>
	/// <returns>true if something went wrong, false every other case</returns>
	static bool CheckFMODErrors(FMOD_RESULT r);
	/// <summary>
	/// For creatinga Reverb3D 
	/// </summary>
	/// <param name="prop">the setting of the reverb</param>
	/// <param name="x">The X position of the reverb</param>
	/// <param name="y">The Y position of the reverb</param>
	/// <param name="maxDistance">The maximun distance of the reverb</param>
	/// <returns>Rhw reverb that is created</returns>
	static FMOD::Reverb3D* createZoneReverb(FMOD_REVERB_PROPERTIES prop, const int & x, const int & y, const float & maxDistance);

	/// <summary>
	/// For getting the preset setting of the reverb
	/// </summary>
	/// <param name="name">the name of the preset</param>
	/// <returns>the preset that is asked for, if the preset does not exist returns the generic one</returns>
	static FMOD_REVERB_PROPERTIES getPresetReverbProperties(std::string name);

	/// <summary>
	/// Creates the geometry.
	/// </summary>
	/// <param name="maxPolygons">The maximum polygons.</param>
	/// <param name="maxVerts">The maximum verts.</param>
	/// <returns>Pointer to the geometry, nullptr if fails</returns>
	static FMOD::Geometry * createGeometry(const int & maxPolygons, const int & maxVerts);
};

