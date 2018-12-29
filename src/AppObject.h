#pragma once
#include "Component.h"
#include <list>
#include "CollisionWorld.h"
#include "Utilities.h"
static int objectNum = 0;

class AppObject
{
public:
	
	AppObject() {
		objectNum++;
		_id = objectNum;
		rect_.x = 0;
		rect_.y = 0;
		rect_.w = 30;
		rect_.h = 30;
		facing.x = 0;
		facing.y = 1;


		color_.a = 255;
		color_.r = 255;
		color_.g = 255;
		color_.b = 255;

		selected_ = false;
		canBeSelected_ = true;
		collider_ = true;
		componentList = std::list<Component*>();
		CollisionWorld::addRect(&rect_, _id);
	};
	~AppObject() {
		CollisionWorld::eraseRect( _id);
	};

	void setCollidable(const bool & b) {
		collider_ = b;
		if (collider_) {
			CollisionWorld::addRect(&rect_, _id);
		}
		else {
			CollisionWorld::eraseRect(_id);
		}
	}

	void addComponent(Component * c) {

		componentList.push_back(c);
		c->init(this);
	}

	Component * getComponent(const char * type) {
		for (auto c : componentList) {
			if (c->getType() == type) {
				return c;
			}
		}
		return nullptr;

	}
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
	virtual void render() {
		
		for (auto c : componentList)
			c->render(this);
	};
	virtual void tick() {
		for (auto c : componentList) {
			c->tick(this);
		}
	};
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
	bool pointInRect(int & x, int & y) {
		SDL_Point p = { x,y };
		return SDL_PointInRect(&p, &rect_);
	}

	int getXMiddle() { return rect_.x + rect_.w / 2; }
	int getYMiddle() { return rect_.y+rect_.h / 2; }

	int getX() { return rect_.x; }
	int getY() { return rect_.y; }
	int getW() { return rect_.w; }
	int getH() { return rect_.h; }
	void setX(const int & x) { rect_.x = x; }
	void setY(const int & y) { rect_.y = y; }
	void setW(const int & w) { rect_.w = w; }
	void setH(const int & h) { rect_.h = h; }

	void setFacing(const float & x, const float & y) {
		facing.x = x; facing.y = y;
	}
	Vector2D getFacing(){
		return facing;
	}


	void setCanBeSeleceted(const bool & b) { canBeSelected_ = b; }
	bool getCanBeSeleceted() { return canBeSelected_; }
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
