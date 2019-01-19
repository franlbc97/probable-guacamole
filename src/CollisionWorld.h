#pragma once
#include <SDL_rect.h>

/// <summary>
/// A primitive collision engine for this project
/// </summary>
class CollisionWorld
{
public:

	/// <summary>
	/// Intializes the collision engine
	/// </summary>
	/// <returns>true if fails, false every other case</returns>
	static bool init();
	/// <summary>
	/// adds a new collider
	/// </summary>
	/// <param name="a">the new rect</param>
	/// <param name="id">the id of the object asociated with that rect</param>
	static void addRect(SDL_Rect * a, int id);
	/// <summary>
	/// for removing a Rect 
	/// </summary>
	/// <param name="id">the id of the AppObject</param>
	static void eraseRect(int id);
	/// <summary>
	/// For checking if that object collides with something
	/// </summary>
	/// <param name="rect">The rect that is gonna be checked</param>
	/// <returns>true if collides, false if not </returns>
	static bool collides(SDL_Rect * rect);


};

