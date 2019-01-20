#pragma once
#include "Component.h"
#include <fmod.hpp>
/// <summary>
/// Component that uses FMOD::Reverb3D
/// </summary>
class Reverb3DComponent: public Component
{
public:
	/// <summary>
	/// Constructor of the Component
	/// </summary>
	/// <param name="props">The porperties of the reverb</param>
	Reverb3DComponent(FMOD_REVERB_PROPERTIES props);
	/// <summary>
	/// Destructor of the Component
	/// </summary>
	~Reverb3DComponent();

	/// <summary>
	/// Initializes the reverb
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns>True if fails, false in every other case</returns>
	virtual bool init(AppObject * obj);
	/// <summary>
	/// Rener the max distance radius of the reverb
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void render(AppObject * obj);
	/// <summary>
	/// Updates the position of the reverb
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void tick(AppObject * obj);
	/// <summary>
	/// Does not handle input events
	/// </summary>
	/// <param name="e"></param>
	/// <param name="obj"></param>
	/// <returns></returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	/// <summary>
	/// Release the Reverb3D
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void release(AppObject * obj);
	virtual const char * getType();

private:
	float maxDistance_;
	FMOD_REVERB_PROPERTIES props_;
	FMOD::Reverb3D * reverb_;
};
