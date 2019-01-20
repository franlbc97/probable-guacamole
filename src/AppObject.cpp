#include "AppObject.h"

AppObject::AppObject()
{
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
}

bool AppObject::handleInput(SDL_Event & e)
{

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
		c->handleInput(e, this);
	}
	return false;
}

int AppObject::getXMiddle()
{
	return rect_.x + rect_.w / 2;
}

int AppObject::getYMiddle()
{
	return rect_.y + rect_.h / 2;
}

int AppObject::getX()
{
	return rect_.x;
}

int AppObject::getY()
{
	return rect_.y;
}

int AppObject::getW()
{
	return rect_.w;
}

int AppObject::getH()
{
	return rect_.h;
}

int AppObject::getId()
{
	return _id;
}
