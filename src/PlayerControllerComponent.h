#pragma once
#include "Component.h"
#include <map>
#include "Utilities.h"
class PlayerControllerComponent
	:public Component
{
public:
	PlayerControllerComponent();
	~PlayerControllerComponent();
	virtual bool init(AppObject * obj);
	virtual void render(AppObject * obj);
	virtual void tick(AppObject * obj);
	virtual bool handleInput(SDL_Event & e, AppObject * obj);
	virtual void release(AppObject * obj);
	virtual const char * getType();
	
	void setFacingByLookingAt(const int & lookx, const int & looky, const int & posx, const int & posy);
	
private:
	void updateKeys(SDL_Event & e, bool Pressed);
	int _movementAmount;
	std::map<SDL_Keycode, bool> keys;
	Vector2D lookingAt;

};
