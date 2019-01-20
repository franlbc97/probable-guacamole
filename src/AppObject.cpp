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


AppObject::~AppObject()
{
	CollisionWorld::eraseRect(_id);
}


void AppObject::setCollidable(const bool & b)
{
	collider_ = b;
	if (collider_) {
		CollisionWorld::addRect(&rect_, _id);
	}
	else {
		CollisionWorld::eraseRect(_id);
	}
}


void AppObject::addComponent(Component * c)
{

	componentList.push_back(c);
	c->init(this);
}


Component * AppObject::getComponent(const char * type)
{
	for (auto c : componentList) {
		if (c->getType() == type) {
			return c;
		}
	}
	return nullptr;

}


bool AppObject::move(const int & x, const int & y)
{
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


void AppObject::render()
{
	for (auto c : componentList)
		c->render(this);
}

void AppObject::tick()
{
	for (auto c : componentList) {
		c->tick(this);
	}
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


bool AppObject::pointInRect(int & x, int & y)
{
	SDL_Point p = { x,y };
	return SDL_PointInRect(&p, &rect_);
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


void AppObject::setX(const int & x)
{
	rect_.x = x;
}

void AppObject::setY(const int & y)
{
	rect_.y = y;
}


void AppObject::setW(const int & w)
{
	rect_.w = w;
}

void AppObject::setH(const int & h)
{
	rect_.h = h;
}


void AppObject::setFacing(const float & x, const float & y)
{
	facing.x = x; facing.y = y;
}


void AppObject::setCanBeSeleceted(const bool & b)
{
	canBeSelected_ = b;
}


bool AppObject::getCanBeSeleceted()
{
	return canBeSelected_;
}


SDL_Rect & AppObject::getRect()
{
	return rect_;
}


int AppObject::getId()
{
	return _id;
}
