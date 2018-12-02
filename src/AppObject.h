#pragma once
#include "Component.h"
#include <list>
class AppObject
{
public:
	AppObject() {
		rect_.x = 0;
		rect_.y = 0;
		rect_.w = 30;
		rect_.h = 30;

		color_.a = 255;
		color_.r = 255;
		color_.g = 255;
		color_.b = 255;

		selected_ = false;
		canBeSelected_ = true;
		componentList = std::list<Component*>();

	};
	~AppObject() {};
	void addComponent(Component * c) {

		componentList.push_back(c);
		c->init(this);
	}
	virtual void render(SDL_Renderer * r) {
		for (auto c : componentList)
			c->render(r, this);
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
				rect_.x += e.motion.xrel;
				rect_.y += e.motion.yrel;
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

	void setCanBeSeleceted(const bool & b) { canBeSelected_ = b; }
	bool getCanBeSeleceted() { return canBeSelected_; }
	SDL_Rect &getRect() { return rect_; };

protected:
	std::list<Component*> componentList;
	bool canBeSelected_;
	bool selected_;
	
	SDL_Rect rect_;
	SDL_Color color_;

};
