#pragma once
#include "Component.h"
#include <fmod.hpp>
class WallComponent:public Component
{
public:
	/// <summary>
	/// Constructor of the component
	/// </summary>
	/// <param name="directOclusion">The direct occlusion of the wall</param>
	/// <param name="reverbOcclusion">The reverb occlusion of the wal</param>
	WallComponent(const float & directOclusion,const float & reverbOcclusion);
	~WallComponent();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns></returns>
	virtual bool init(AppObject * obj);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void render( AppObject * obj);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void tick(AppObject * obj);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="e">The event</param>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns></returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void release(AppObject * obj);
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	virtual const char * getType();

	/// <summary>
	/// Gets the direct occlusion.
	/// </summary>
	/// <returns></returns>
	float getDirectOcclusion();

	/// <summary>
	/// Sets the direct occlusion.
	/// </summary>
	/// <param name="newValue">The new value.</param>
	void setDirectOcclusion(const float & newValue);
	
	
	/// <summary>
	/// Gets the reverb occlusion.
	/// </summary>
	/// <returns></returns>
	float getReverbOcclusion();

	
	/// <summary>
	/// Sets the reverb occlusion.
	/// </summary>
	/// <param name="newValue">The new value.</param>
	void setReverbOcclusion(const float & newValue);
	

	

private:
	FMOD::Geometry* geo_;
	int polygonIndex;
	float _directOclusion;
	float _reverbOcclusion;
	int indexes[4];

};


