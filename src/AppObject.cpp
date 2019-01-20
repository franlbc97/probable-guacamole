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

int AppObject::getId()
{
	return _id;
}
