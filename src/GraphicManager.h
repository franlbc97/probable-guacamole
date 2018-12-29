#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
class GraphicManager
{
public:
	
	static bool init();
	static bool tick();
	static bool release();



	static SDL_Renderer* getRenderer();
	static SDL_Window * getWindow();
	
	static void moveCamera(const int & x, const int & y);
	static void setCameraPos(const int & x, const int & y);
	static SDL_Rect getRectRelativeToCamera(const SDL_Rect & r);
	static bool isInCamera(const SDL_Rect & r);


	

	static void present();
	static void clear();
	static void setColor(const int & r, const int & g, const int & b, const int & a);
	static void drawRect(const SDL_Rect & rect, const SDL_Color & color);
	static void drawLine(const int &x1, const int &y1, const int &x2, const int &, const SDL_Color & color);
	static void drawCircle(const int & x, const int & y, const int & radius, SDL_Color color);

private:

};

