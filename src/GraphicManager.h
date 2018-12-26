#pragma once
#include<SDL_rect.h>
#include<SDL_render.h>
class GraphicManager
{
public:
	
	static bool init();

	static SDL_Renderer* getRenderer();
	static SDL_Window * getWindow();
	
	static SDL_Rect getRectRelativeToCamera(const SDL_Rect & r);
	static bool isInCamera(const SDL_Rect & r);
private:

};

