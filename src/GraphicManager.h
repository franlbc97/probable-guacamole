#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
class GraphicManager
{
public:
	
	static bool init();
	static bool tick();

	static SDL_Renderer* getRenderer();
	static SDL_Window * getWindow();
	
	static void moveCamera(const int & x, const int & y);
	static void setCameraPos(const int & x, const int & y);
	static SDL_Rect getRectRelativeToCamera(const SDL_Rect & r);
	static bool isInCamera(const SDL_Rect & r);
private:

};

