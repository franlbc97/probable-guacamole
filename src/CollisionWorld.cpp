#include "CollisionWorld.h"
#include <map>
#include <utility>

static std::map<int, SDL_Rect*> world;

bool CollisionWorld::init()
{
	world = std::map<int, SDL_Rect*>();
	
	return true;
}

void CollisionWorld::addRect(SDL_Rect * a, int id)
{
	try
	{
		world.at(id);
	}
	catch (const std::out_of_range&e)
	{
		world.emplace(std::make_pair(id, a));

	}
}

void CollisionWorld::eraseRect(int id)
{
	try
	{
		world.at(id);
		world.erase(id);

	}
	catch (const std::exception&)
	{

	}

}

bool CollisionWorld::collides(SDL_Rect  * rect)
{
	SDL_Rect inter;
	for (auto r : world) {
		if (r.second!=rect) {
			if (SDL_TRUE == SDL_IntersectRect(r.second, rect, &inter)) {
				return true;
			}
		}
	}
	return false;
}
