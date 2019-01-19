#pragma once
#include <SDL_events.h>
#define SCALE_FACTOR 1.0f
class AppObject;

/// <summary>
/// The abstract class of a Comoponent
/// </summary>
class Component
{
public:
	/// <summary>
	/// Abstract virtual method for init the component
	/// </summary>
	/// <param name="obj"> The current object</param>
	/// <returns>if the component initialized correctily</returns>
	virtual bool init(AppObject * obj) = 0;
	/// <summary>
	/// Abstract virtual method for rendering the component if needed
	/// </summary>
	/// <param name="obj">the object that is asociated with this component</param>
	virtual void render(AppObject * obj) =0;
	/// <summary>
	/// Abstract virtual method for update the component if needed
	/// </summary>
	/// <param name="obj"></param>
	virtual void tick(AppObject * obj) = 0;
	/// <summary>
	/// Abstract virtual method for handeling the input
	/// </summary>
	/// <param name="e">the event</param>
	/// <param name="obj">the AppObject that is assoicated</param>
	/// <returns>true if there is no need to check other components</returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj) = 0;
	/// <summary>
	/// For realisng the things that involves the component
	/// </summary>
	/// <param name="obj">the AppObject that is assoicated with the component</param>
	virtual void release(AppObject * obj) = 0;
	/// <summary>
	/// returns the type the Component
	/// </summary>
	/// <returns>an string with the name of the game AppObject</returns>
	virtual const char * getType() = 0;
	
};
class DragMouseComponent: public Component
{
public:
	DragMouseComponent() {};
	virtual ~DragMouseComponent() {};
	virtual bool init(AppObject * obj);
	virtual void render( AppObject * obj) {}
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj) {};

private:

};









