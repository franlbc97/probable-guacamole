#pragma once
#include "Component.h"
#include <list>
#include "CollisionWorld.h"
#include "Utilities.h"
static int objectNum = 0;

/// <summary>
/// Object of the scene
/// </summary>
class AppObject
{
public:
	/// <summary>
	/// The constructo of AppObject
	/// </summary>
	AppObject();
	/// <summary>
	/// The destructor of AppObject
	/// </summary>
	~AppObject();

	/// <summary>
	/// Add/remove from the collision engine that object
	/// </summary>
	/// <param name="b">The new value</param>
	void setCollidable(const bool & b);

	/// <summary>
	/// Adds a component to the AppObject
	/// </summary>
	/// <param name="c">The compoent that is going to be added</param>
	void addComponent(Component * c);

	/// <summary>
	/// Obtains the component with the type
	/// </summary>
	/// <param name="type">The type of the component that is searched</param>
	/// <returns>
	/// The component if it found, nullptr in every other case
	/// </returns>
	Component * getComponent(const char * type);

	/// <summary>
	/// For moving the AppObject
	/// </summary>
	/// <param name="x">The amount of movement in the X axis</param>
	/// <param name="y">The amount of movement in the Y axis</param>
	/// <returns>
	/// True if cant move, false in every other case
	/// </returns>
	virtual bool move(const int & x, const int & y);

	/// <summary>
	/// Renders the AppObject
	/// </summary>
	virtual void render();

	/// <summary>
	/// Updates every component of the AppObject
	/// </summary>
	virtual void tick();

	/// <summary>
	/// Sends to every component of the object the handle event
	/// </summary>
	/// <param name="e">The event</param>
	/// <returns>
	/// True if there is no need of checkin other Objects, false every other case
	/// </returns>
	virtual bool handleInput(SDL_Event & e);

	/// <summary>
	/// For checking if the point is inside the object
	/// </summary>
	/// <param name="x">The X position of the point</param>
	/// <param name="y">The Y position of the point</param>
	/// <returns>
	/// true if the point is inside the object, false in every other case
	/// </returns>
	bool pointInRect(int & x, int & y);

	/// <summary>
	/// For getting the X position of the midle of the rect
	/// </summary>
	/// <returns>
	/// X position of the midle of the rect
	/// </returns>
	int getXMiddle();

	/// <summary>
	/// For getting the Y position of the midle of the rect
	/// </summary>
	/// <returns>
	/// Y position of the midle of the rect
	/// </returns>
	int getYMiddle();

	/// <summary>
	/// For gettin the X position of the rect
	/// </summary>
	/// <returns>
	/// X position of the rect
	/// </returns>
	int getX();


	/// <summary>
	/// For gettin the Y position of the rect
	/// </summary>
	/// <returns>
	/// Y position of the rect
	/// </returns>
	int getY();

	/// <summary>
	/// For gettin the width of the rect
	/// </summary>
	/// <returns>
	/// Width of the rect
	/// </returns>
	int getW();

	/// <summary>
	/// For gettin the Height of the rect
	/// </summary>
	/// <returns>
	/// Height of the rect
	/// </returns>
	int getH();


	/// <summary>
	/// For setting tha X position of the AppObject
	/// </summary>
	/// <param name="x">The new X position</param>
	void setX(const int & x);

	/// <summary>
	/// For setting tha Y position of the AppObject
	/// </summary>
	/// <param name="y">The new Y position</param>
	void setY(const int & y);

	/// <summary>
	/// For setting tha width of the AppObject
	/// </summary>
	/// <param name="w">The new width</param>
	void setW(const int & w);

	/// <summary>
	/// For setting tha heigth of the AppObject
	/// </summary>
	/// <param name="h">The new heigth</param>
	void setH(const int & h);
	
	/// <summary>
	/// For setting the direction that the object is facing
	/// </summary>
	/// <param name="x">The x.</param>
	/// <param name="y">The y.</param>
	void setFacing(const float & x, const float & y);


	/// <summary>
	/// Foe getting the direction that is facing the object
	/// </summary>
	/// <returns>
	/// Direction that is facing the object
	/// </returns>
	Vector2D getFacing() {
		return facing;
	}

	/// <summary>
	/// For setting if this object can be selected
	/// </summary>
	/// <param name="b">True/False</param>
	void setCanBeSeleceted(const bool & b);

	/// <summary>
	/// For getting if this AppObject can be selected
	/// </summary>
	/// <returns>
	/// True if can be selected, false every other caase
	/// </returns>
	bool getCanBeSeleceted();

	/// <summary>
	/// For getting the rect of the AppObject
	/// </summary>
	/// <returns>
	/// Rect of the AppObject
	/// </returns>
	SDL_Rect &getRect();

	/// <summary>
	/// For getting the id of the AppObject
	/// </summary>
	/// <returns>
	/// id of the AppObject
	/// </returns>
	int getId();

protected:
	/// <summary>
	/// The facing
	/// </summary>
	Vector2D facing;
	/// <summary>
	/// The ID of the object
	/// </summary>
	int _id;
	/// <summary>
	/// list of the components asociated with the object
	/// </summary>
	std::list<Component*> componentList;

	/// <summary>
	/// The can be selected value
	/// </summary>
	bool canBeSelected_;
	/// <summary>
	/// The selected value
	/// </summary>
	bool selected_;
	/// <summary>
	/// The collider value
	/// </summary>
	bool collider_;
	
	SDL_Rect rect_;
	SDL_Color color_;

};
