#pragma once
#include "Component.h"

/// <summary>
/// Component for movement
/// </summary>
class MoveComponent :
	public Component
{
public:
	/// <summary>
	/// An enum for the directions 
	/// </summary>
	enum Direction
	{
		DIR_NORTH,
		DIR_NORTH_EAST,
		DIR_EAST,
		DIR_SOUTH_EAST,
		DIR_SOUTH,
		DIR_SOUTH_WEST,
		DIR_WEST,
		DIR_NORTH_WEST,
	};
	/// <summary>
	/// COnstructor of the component
	/// </summary>
	/// <param name="max">The max amount of movement</param>
	MoveComponent(float max);
	/// <summary>
	/// The destructor of the component
	/// </summary>
	~MoveComponent();
	/// <summary>
	/// Initializes the component
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns></returns>
	virtual bool init(AppObject * obj);
	/// <summary>
	/// Does not affect to the rendering
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void render( AppObject * obj);
	/// <summary>
	/// Updates the position of the AppObject
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void tick(AppObject * obj);
	/// <summary>
	/// Handles the the input of the object
	/// </summary>
	/// <param name="e">The event</param>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns></returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	/// <summary>
	/// Release every that involves MoveComponent
	/// </summary>
	/// <param name="obj">The object that is asociated with componen</param>
	virtual void release(AppObject * obj);
	/// <summary>
	/// Returns the the type of the component
	/// </summary>
	/// <returns>"MoveComponent" in every case</returns>
	virtual const char * getType();

private:
	float maxVelocity;
	


};
