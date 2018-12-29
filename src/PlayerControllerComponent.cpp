#include "PlayerControllerComponent.h"
#include "AppObject.h"
#include "GraphicManager.h"

PlayerControllerComponent::PlayerControllerComponent()
{
}

PlayerControllerComponent::~PlayerControllerComponent()
{
}

bool PlayerControllerComponent::init(AppObject * obj)
{
	keys.emplace(std::make_pair(SDLK_w, false));
	keys.emplace(std::make_pair(SDLK_s, false));
	keys.emplace(std::make_pair(SDLK_d, false));
	keys.emplace(std::make_pair(SDLK_a, false));
	obj->setCanBeSeleceted(false);
	return false;
}

void PlayerControllerComponent::render( AppObject * obj)
{
	int lengtLine = (obj->getW()>obj->getH()) ?obj->getW() : obj->getH();
	lengtLine += 15;
	int x1, y1, x2, y2;
	x1 = obj->getXMiddle();
	y1 = obj->getYMiddle();
	x2 = x1 + lookingAt.x*lengtLine;
	y2 = y1 + lookingAt.y*lengtLine;

	GraphicManager::drawLine(x1,y1,x2,y2, { 255,0,0,255 });
	GraphicManager::drawRect({ x2 - 5,y2 - 5,10,10 }, { 255, 0, 0, 255 });

	
}

void PlayerControllerComponent::tick(AppObject * obj)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	setFacingByLookingAt(x, y, obj->getXMiddle(),obj->getYMiddle());
	obj->setFacing(lookingAt.x, lookingAt.y);
	//go up
	if (keys.at(SDLK_w)) {
		obj->move(0, -5);
	}
	//go down
	else if (keys.at(SDLK_s)) {
		obj->move(0, 5);
	}
	//go left
	if (keys.at(SDLK_a)) {
		obj->move(-5, 0);

	}
	//go right
	else if (keys.at(SDLK_d)) {
		obj->move(5, 0);

	}
	
}

bool PlayerControllerComponent::handleInput(SDL_Event & e, AppObject * obj)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		updateKeys(e, true);
		break;
	case SDL_KEYUP:
		updateKeys(e, false);
		break;
	default:
		break;
	}
	return false;
}

void PlayerControllerComponent::release(AppObject * obj)
{
}

const char * PlayerControllerComponent::getType()
{
	return "PlayerControllerComponent";
}

void PlayerControllerComponent::setFacingByLookingAt(const int & lookx, const int & looky, const int & posx, const int & posy)
{
	lookingAt.x = lookx - posx;
	lookingAt.y = looky - posy;
	float legnth = sqrtf(lookingAt.x*lookingAt.x + lookingAt.y*lookingAt.y);
	lookingAt.x /= legnth;
	lookingAt.y /= legnth;



}

void PlayerControllerComponent::updateKeys(SDL_Event & e, bool pressed)
{
	try
	{
		keys.at(e.key.keysym.sym) = pressed;
	}
	catch (const std::exception&)
	{

	}
}
