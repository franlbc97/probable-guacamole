#pragma once
#include "Component.h"
#include <fmod.hpp>

/// <summary>
/// Listener componet
/// </summary>
/// <seealso cref="Component" />
class ListenerComponent : public Component
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="ListenerComponent"/> class.
	/// </summary>
	ListenerComponent() {};
	/// <summary>
	/// Finalizes an instance of the <see cref="ListenerComponent"/> class.
	/// </summary>
	~ListenerComponent() {};

	/// <summary>
	/// Intialize the listener
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns>true if fails, every other case, false</returns>
	virtual bool init(AppObject * obj);
	
	/// <summary>
	/// Abstract virtual method for rendering the component if needed
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void render(AppObject * obj);
	/// <summary>
	/// Updates the position and the orientation of the listener
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void tick(AppObject * obj);

	/// <summary>
	/// Doesn't use the handle input
	/// </summary>
	/// <param name="e">the event</param>
	/// <param name="obj">The object that is asociated with component</param>
	/// <returns>
	/// false in every case
	/// </returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj);

	/// <summary>
	/// Realease the things that involves the listener
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void release(AppObject * obj);

	/// <summary>
	/// For knowing the type of the component
	/// </summary>
	/// <returns>
	/// returns in every case "ListenerComponent"
	/// </returns>
	virtual const char * getType();

	/// <summary>
	/// For changing the position of the listener
	/// </summary>
	/// <param name="x">X position</param>
	/// <param name="y">Y position</param>
	/// <param name="z">Z position</param>
	void changePosition3D(const int & x, const int & y, const int & z);

	/// <summary>
	/// For changing the orientation of the object
	/// </summary>
	/// <param name="x">X angle</param>
	/// <param name="y">Y angle</param>
	/// <param name="z">Z angle</param>
	void changeOrientation(const float & x, const float & y, const float & z);


};