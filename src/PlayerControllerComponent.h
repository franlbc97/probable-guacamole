#pragma once
#include "Component.h"
#include <map>
#include "Utilities.h"

/// <summary>
/// For controlling the player
/// </summary>
class PlayerControllerComponent
	:public Component
{
public:
	/// <summary>
	/// The constructor of the PlayerControllerComponent
	/// </summary>
	PlayerControllerComponent();
	/// <summary>
	/// The destructor of the PlayerControllerComponent
	/// </summary>
	~PlayerControllerComponent();
	/// <summary>
	/// For initializing the player controller
	/// </summary>
	/// <param name="obj">The object that is asociated with componen/param>
	/// <returns>True if something fails, true in every other case</returns>
	virtual bool init(AppObject * obj);
	/// <summary>
	/// Renders the direction that is facing the player
	/// </summary>
	/// <param name="obj">The object that is asociated with componen</param>
	virtual void render(AppObject * obj);
	/// <summary>
	/// Updates the position and orientiation of the AppObject
	/// </summary>
	/// <param name="obj">The object that is asociated with componen</param>
	virtual void tick(AppObject * obj);
	/// <summary>
	/// Checks if any key of movement is pressed/realesed
	/// </summary>
	/// <param name="e">The Event</param>
	/// <param name="obj">The object that is asociated with componen</param>
	/// <returns></returns>
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	/// <summary>
	/// Release everything that involves the PlayerControllerComponent
	/// </summary>
	/// <param name="obj">The object that is asociated with component</param>
	virtual void release(AppObject * obj);
	/// <summary>
	/// For getting the type of Component
	/// </summary>
	/// <returns>"PlayerControllerComponent in every case"</returns>
	virtual const char * getType();
	
	void setFacingByLookingAt(const int & lookx, const int & looky, const int & posx, const int & posy);
	
private:
	void updateKeys(SDL_Event & e, bool Pressed);
	int _movementAmount;
	std::map<SDL_Keycode, bool> keys;
	Vector2D lookingAt;

};
