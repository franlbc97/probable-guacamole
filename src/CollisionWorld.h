#pragma once
#include <SDL_rect.h>
class CollisionWorld
{
public:
	static bool init();
	static void addRect(SDL_Rect * a, int id);
	static void eraseRect(int id);
	static bool collides(SDL_Rect * rect);

private:


};

