#pragma once
#include "Component.h"
#include <list>
#include "CollisionWorld.h"
#include "Utilities.h"
static int objectNum = 0;

/// <summary>
/// 
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
	~AppObject() {
		CollisionWorld::eraseRect( _id);
	};

	/// <summary>
	/// Add/remove from the collision engine that object
	/// </summary>
	/// <param name="b"></param>
	void setCollidable(const bool & b) {
		collider_ = b;
		if (collider_) {
			CollisionWorld::addRect(&rect_, _id);
		}
		else {
			CollisionWorld::eraseRect(_id);
		}
	}

	/// <summary>
	/// Adds a component to the AppObject
	/// </summary>
	/// <param name="c">The compoent that is going to be added </param>
	void addComponent(Component * c) {

		componentList.push_back(c);
		c->init(this);
	}

	/// <summary>
	/// Obtains the component with the type
	/// </summary>
	/// <param name="type">The type of the component that is searched</param>
	/// <returns>The component if it found, nullptr in every other case</returns>
	Component * getComponent(const char * type) {
		for (auto c : componentList) {
			if (c->getType() == type) {
				return c;
			}
		}
		return nullptr;

	}

	/// <summary>
	/// For moving the AppObject
	/// </summary>
	/// <param name="x">The amount of movement in the X axis</param>
	/// <param name="y">The amount of movement in the Y axis</param>
	/// <returns>True if cant move, false in every other case</returns>
	virtual bool move(const int & x, const int & y) {
		rect_.x += x;
		rect_.y += y;
		if (collider_) {
			if (CollisionWorld::collides(&rect_)) {
				rect_.x -= x;
				rect_.y -= y;
				return false;
			}
		}
		return true;
	}

	/// <summary>
	/// Renders the AppObject
	/// </summary>
	virtual void render() {
		
		for (auto c : componentList)
			c->render(this);
	};

	/// <summary>
	/// Updates every component of the AppObject
	/// </summary>
	virtual void tick() {
		for (auto c : componentList) {
			c->tick(this);
		}
	};

	/// <summary>
	/// Sends to every component of the object the handle event
	/// </summary>
	/// <param name="e">The event</param>
	/// <returns>True if there is no need of checkin other Objects, false every other case</returns>
	virtual bool handleInput(SDL_Event & e) {
		int x, y;
		switch (e.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			if (e.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&x, &y);
				if (pointInRect(x, y) && canBeSelected_) {
					selected_ = true;
					return true;
				}
			}
			break;
		case SDL_MOUSEMOTION:
			if (selected_) {
				move(e.motion.xrel, e.motion.yrel);
				return true;
			}
			break;
		case SDL_MOUSEBUTTONUP:

			if (selected_) {
				selected_ = false;
				return true;
			}
			break;
		default:
			break;
		}
		for (auto c : componentList) {
			c->handleInput(e,this);
		}
		return false;
	}

	/// <summary>
	/// For checking if the point is inside the object
	/// </summary>
	/// <param name="x">The X position of the point</param>
	/// <param name="y">The Y position of the point</param>
	/// <returns></returns>
	bool pointInRect(int & x, int & y) {
		SDL_Point p = { x,y };
		return SDL_PointInRect(&p, &rect_);
	}

	/// <summary>
	/// For getting the X position of the midle of the rect
	/// </summary>
	/// <returns>X position of the midle of the rect</returns>
	int getXMiddle() { return rect_.x + rect_.w / 2; }
	/// <summary>
	/// For getting the Y position of the midle of the rect
	/// </summary>
	/// <returns>Y position of the midle of the rect</returns>
	int getYMiddle() { return rect_.y+rect_.h / 2; }

	/// <summary>
	/// For gettin the X position of the rect
	/// </summary>
	/// <returns>X position of the rect</returns>
	int getX() { return rect_.x; }
	/// <summary>
	/// For gettin the Y position of the rect
	/// </summary>
	/// <returns>Y position of the rect</returns>
	int getY() { return rect_.y; }
	/// <summary>
	/// For gettin the width of the rect
	/// </summary>
	/// <returns>Width of the rect</returns>
	int getW() { return rect_.w; }
	/// <summary>
	/// For gettin the X position of the rect
	/// </summary>
	/// <returns>X position of the rect</returns>
	int getH() { return rect_.h; }
	/// <summary>
	/// For setting tha X position of the AppObject
	/// </summary>
	/// <param name="x">The new X position</param>
	void setX(const int & x) { rect_.x = x; }
	/// <summary>
	/// For setting tha Y position of the AppObject
	/// </summary>
	/// <param name="x">The new Y position</param>
	void setY(const int & y) { rect_.y = y; }
	/// <summary>
	/// For setting tha width of the AppObject
	/// </summary>
	/// <param name="x">The new width</param>
	void setW(const int & w) { rect_.w = w; }
	/// <summary>
	/// For setting tha heigth of the AppObject
	/// </summary>
	/// <param name="x">The new heigth</param>
	void setH(const int & h) { rect_.h = h; }

	void setFacing(const float & x, const float & y) {
		facing.x = x; facing.y = y;
	}

	/// <summary>
	/// Foe getting the direction that is facing the object
	/// </summary>
	/// <returns>Direction that is facing the object</returns>
	Vector2D getFacing(){
		return facing;
	}

	/// <summary>
	/// For setting if this object can be selected
	/// </summary>
	/// <param name="b">True/False</param>
	void setCanBeSeleceted(const bool & b) { canBeSelected_ = b; }
	/// <summary>
	/// For getting if this AppObject can be selected
	/// </summary>
	/// <returns>True if can be selected, false every other caase</returns>
	bool getCanBeSeleceted() { return canBeSelected_; }

	/// <summary>
	/// For getting the recet of the AppObject
	/// </summary>
	/// <returns> Rect of the AppObject</returns>
	SDL_Rect &getRect() { return rect_; };

protected:	
	Vector2D facing;
	int _id;
	std::list<Component*> componentList;
	bool canBeSelected_;
	bool selected_;
	bool collider_;
	
	SDL_Rect rect_;
	SDL_Color color_;

};
